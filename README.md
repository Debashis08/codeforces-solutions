# codeforces-solutions

![Build Status](https://img.shields.io/github/actions/workflow/status/Debashis08/codeforces-solutions/validate.yaml?style=flat-square&label=Build%20%26%20Test)
![Latest Release](https://img.shields.io/github/v/release/Debashis08/codeforces-solutions?style=flat-square&label=Latest%20Release&color=blue)
![License](https://img.shields.io/github/license/Debashis08/codeforces-solutions?style=flat-square&color=brown)

A well-structured collection of solutions for Codeforces contests and practice problems. The repository includes a fully automated CI/CD pipeline for building, testing, PR labeling, and release-note generation, supporting a disciplined and scalable competitive programming workflow.

### Repository Structure

```text
codeforces-solutions
├── .github/                 # CI/CD Workflows (Auto-labeling, Release Drafter)
├── src/
│   ├── contests/            # Solutions for live contests (e.g., CFR-1034)
│   └── problemsets/         # Upsolving and practice problems by rating
│
├── tests/                   # Test Automation
│   ├── contests/            # Input/Output text files matching src/ structure
│   ├── problemsets/         # Practice test cases
│   ├── allTestRunner.cpp    # Tool to run all tests in bulk
│   └── singleTestRunner.cpp # Tool to test a single solution
│
├── template.cpp             # Starting template for new solutions
├── CONTRIBUTING.md          # Guidelines for contributing
└── README.md                # Project documentation