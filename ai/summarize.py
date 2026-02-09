import os
from pathlib import Path
import google.generativeai as genai

# ---- Configuration ----
api_key = os.getenv("GOOGLE_API_KEY")
if not api_key:
    raise RuntimeError("GOOGLE_API_KEY not found")

today = os.getenv("TODAY")
if not today:
    raise RuntimeError("TODAY env variable not set")

genai.configure(api_key=api_key)

model = genai.GenerativeModel("gemini-2.5-flash")

# ---- Locate today's solutions ----
base = Path(f"solutions/{today}")
base = Path(f"solutions/2026-02-08")
print("Looking in:", base)

if not base.exists():
    print("No solutions found for today.")
    exit(0)

readme = base / "README.md"

# content = f"""# 📅 Daily CP Solutions — {today}
content = f"""# 📅 Daily CP Solutions — 2026-02-08

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---
"""

# ---- Process each solution file ----
for file in sorted(base.iterdir()):
    if file.suffix not in [".cpp", ".py"]:
        continue

    platform = "LeetCode" if file.name.startswith("leetcode") else "GeeksforGeeks"
    code = file.read_text()

    prompt = f"""
You are a competitive programming mentor.

Analyze the solution below and respond using ONLY the following plain-text format.
Do NOT use markdown.
Do NOT include code.
Do NOT include backticks.
Do NOT add extra sections.

FORMAT (follow exactly):

Problem Insight:
<1–2 concise lines>

Approach:
<core idea in 2–3 lines>

Time Complexity:
<Big-O with 1-line justification>

Space Complexity:
<Big-O with 1-line justification>

Optimization Notes:
<Is it optimal? Why or what can be improved?>

CODE:
{code}
"""


    response = model.generate_content(prompt)

    content += f"""
## 🔹 {file.stem.replace('_', ' ').title()}
**Platform:** {platform}

{response.text}

### 💻 Implementation
```{file.suffix[1:]}
{code}
```
"""

readme.write_text(content)
print("README generated:", readme)