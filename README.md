**_How to Commit new changes to the repository_**

You can contribute to this repository in Two ways:

**1. Using the Github website**
If you want to edit the files in the repository using the Github website, follow the steps below:

1. Go to the repository
2. Click on the file you want to edit.
3. Click on the edit button.
4. Make changes to the file.
5. Scroll down to the bottom of the page and write a commit message.
6. Click on the commit changes button.

If you want to add a new file to the repository, follow the steps below:

1. Go to the repository.
2. Click on the add file button.
3. Click on the create new file button.
4. Type the file name and write the content of the file.
5. Scroll down to the bottom of the page and write a commit message.
6. Click on the commit new file button.

**2. Using the Git Bash**
If you don't have any github account and want to contribute to the repository using the Git Bash, follow the steps [From here](#section-1)

1. Clone the repository to your local machine using the command:

```bash
git clone https://github.com/istiaqueahmedarik/LinkedList
```

2. Make changes to the files in the repository.

3. Add the changes to the staging area using the command:

```bash
git add .
```

4. Commit the changes to the repository using the command:

```bash
git commit -m "Commit message"
```

5. Push the changes to the remote repository using the command:

```bash
git push origin master
```

**_How to pull changes from the remote repository_**

```bash
git pull origin master
```

**_How to create a new branch_**

```bash

git checkout -b <branch_name>

```

**_How to switch to a branch_**

```bash
git checkout <branch_name>
```

**_How to merge a branch to master_**

```bash
git checkout master
git merge <branch_name>
```

<h2 id="section-1">How to login to github and setup in your local machine
</h2>

1. Create a github account
2. Install git in your local machine, you can download it from [here](https://git-scm.com/downloads). Then follow the instructions to install it.
3. Open git bash and type the following command to configure your name and email address.

```bash
git config --global user.name "Your Name"
git config --global user.email "Your Email"
```

4. login to your github account and create a new repository.
5. Copy the url of the repository and clone it to your local machine using the command:

```bash
git clone <url>
```

6. Now you can see the repository in your local machine. You can make changes to the files in the repository and commit the changes to the repository.
