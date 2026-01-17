import os
from pathlib import Path
import google.generativeai as genai

# genai.configure(api_key=os.getenv("AIzaSyBi9oEBLqt0Hq-PACsHEzTuFaIlQ0H20oY"))
# Pass the string directly if you aren't using an environment variable
genai.configure(api_key="AIzaSyBi9oEBLqt0Hq-PACsHEzTuFaIlQ0H20oY")
model = genai.GenerativeModel("gemini-2.5-flash")

# today = os.getenv("2026-01-17")
base = Path(f"solutions/2026-01-17")
print(base)
if not base.exists():
    print("No solutions found for today.")
    exit(0)

readme = base / "README.md"
content = f"# Daily CP Solutions (2026-01-17)\n\n"

for file in base.iterdir():
    if file.suffix not in [".cpp", ".py"]:
        continue

    platform = "LeetCode" if file.name.startswith("leetcode") else "GFG"
    code = file.read_text()

    prompt = f"""
Analyze the following competitive programming solution.

Provide:
1. Problem summary
2. Current approach
3. Time complexity
4. Space complexity
5. Optimized approach suggestion (if any)

Code:
{code}
"""

    response = model.generate_content(prompt)

    content += f"""
## 🔹 {file.stem.replace('_', ' ').title()}
**Platform:** {platform}

{response.text}

"""
