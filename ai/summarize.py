import os
from pathlib import Path
import google.generativeai as genai

# TEMPORARY: manual testing only
genai.configure(api_key=os.getenv("GEMINI_API_KEY"))


model = genai.GenerativeModel("gemini-2.5-flash")

base = Path("solutions/2026-01-17")
print("Looking in:", base)

if not base.exists():
    print("No solutions found.")
    exit(0)

readme = base / "README.md"
content = "# Daily CP Solutions (2026-01-17)\n\n"

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
5. Optimized approach suggestion

Code:
{code}
"""

    response = model.generate_content(prompt)

    content += f"""
## 🔹 {file.stem.replace('_', ' ').title()}
**Platform:** {platform}

{response.text}

```{file.suffix[1:]}
{code}
"""
readme.write_text(content)

print("README generated successfully at:", readme)