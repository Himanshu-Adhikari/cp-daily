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
print("Looking in:", base)

if not base.exists():
    print("No solutions found for today.")
    exit(0)

readme = base / "README.md"

content = f"""# 📅 Daily CP Solutions — {today}

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
You are an expert competitive programming mentor.

Analyze the solution below  and respond concisely but thoughtfully using this structure:

Problem Insight:
- What problem is being solved (1–2 lines).

Approach:
- Key idea and algorithm used (short and precise).

Time Complexity:
- Big-O with brief justification.

Space Complexity:
- Big-O with brief justification.

Optimization Notes:
- Is this optimal?
- If yes, explain why briefly.
- If no, suggest a better approach in 1–2 lines.

Do NOT repeat the code.
Do NOT be verbose.
Do NOT add extra sections.

Code:
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
"""

readme.write_text(content)
print("README generated:", readme)