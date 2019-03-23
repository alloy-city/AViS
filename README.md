# AViS - Alloy Virtual Space
A multi-platform virtual space for learning and teaching in real time.

---

## How to contribute
### First time / new computer
1) Clone the repository:
```shell
git clone https://github.com/alloy-city/AViS.git
```
2) Get into the newly created repository:
```shell
cd AViS
```
3) Create your branch:
```shell
git checkout -b <branch_name>
```
4) Start messing around.

---
### Everyday workflow
1) Get latest version of dev branch
```shell
git checkout dev
git pull
```
2) Merge dev into the branch you're working on
```shell
git checkout <branch_im_working_on>
git merge dev
```
3) Resume your work. Add/commit as you go.
4) Once you're satisfied with your changes — feature is working, tests passing, bug fixed, etc. — repete steps 1 and 2 to make sure your branch is compatible with the latest dev branch.
5) Upload your changes
```shell
git push
```
6) Make a Pull Request.
