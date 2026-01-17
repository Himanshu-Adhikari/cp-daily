# 📌 CP Daily Automation (LeetCode + GFG)

This repository automates the tracking and documentation of my daily competitive programming practice using **GitHub Actions** and **Gemini 2.5 Flash**.

Each day’s solutions are automatically analyzed and summarized into **concise, interview-ready explanations** including:

* Problem insight
* Core approach
* Time & space complexity
* Optimization notes

---

## 🧠 How It Works

1. I add my daily solutions locally (C++ / Python).
2. A scheduled GitHub Action:

   * Detects today’s solutions
   * Uses Gemini 2.5 Flash to generate summaries
   * Creates/updates a daily `README.md`
   * Commits everything automatically

No manual documentation required.

---

## 📁 Folder Structure

```
cp-daily/
│
├── solutions/
│   └── YYYY-MM-DD/
│       ├── leetcode_<problem_name>.cpp / .py
│       ├── gfg_<problem_name>.cpp / .py
│       └── README.md   # auto-generated
│
├── ai/
│   └── summarize.py
│
└── .github/
    └── workflows/
        └── daily.yml
```

---

## 🔑 Naming Rules

* Prefix LeetCode files with `leetcode_`
* Prefix GeeksforGeeks files with `gfg_`
* Supported languages: `.cpp`, `.py`
* One folder per day (`YYYY-MM-DD`)

---

## ▶️ Daily Usage

1. Solve problems.
2. Save them like:

   ```
   solutions/2026-01-17/leetcode_two_sum.cpp
   solutions/2026-01-17/gfg_redundant_brackets.py
   ```
3. Push the code (optional).
4. Automation handles the rest.

---

## 🤖 Automation Details

* **CI/CD:** GitHub Actions
* **AI Model:** Gemini 2.5 Flash
* **Trigger:** Scheduled (cron) + manual trigger

---

## 🔐 Secrets Setup (Required)

Add the following GitHub secret:

* **Name:** `GOOGLE_API_KEY`
* **Value:** Your Gemini API key

Path:

```
GitHub → Repo → Settings → Secrets and variables → Actions
```

⚠️ Never hardcode API keys in code or workflows.

---

## ⏰ Changing the Schedule

GitHub Actions uses **UTC time**.

Examples:

* **9:00 PM IST** → `30 15 * * *`
* **10:00 PM IST** → `30 16 * * *`

Edit the cron value in:

```
.github/workflows/daily.yml
```

---

## 🎯 Purpose

* Build consistency in problem solving
* Preserve insights, not just solutions
* Reduce manual effort
* Create a searchable revision log

---

**Consistency > intensity.**
This repository is part of an ongoing daily learning challenge.
