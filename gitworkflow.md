# git workflow步骤
-  **Create a repository**
>   Click the "Create New Repository" Menu and select the path to create. And Create a new Repository by clicking the "Create" button. the new repository was originally a seperate dictionary on the local machine, and added a .git folder to hold the version and other information after creating the repository.

![*Create Repository*](https://imgsa.baidu.com/exp/w=500/sign=2d2c6fd3d5c451daf6f60ceb86ff52a5/b64543a98226cffc28ee483fb1014a90f703ea73.jpg)

![*Create Repository*](https://imgsa.baidu.com/exp/w=500/sign=409bd9f1590fd9f9a0175569152cd42b/caef76094b36acaf85be607174d98d1000e99ce5.jpg)
- **Clone(add a new file)**
>Enter the local repository dictionary and create a new text file, such as"testGIT.txt". Click the Rescan button in git and the file appears in the UnstagedChanges list.

![Clone](https://imgsa.baidu.com/exp/w=500/sign=952af647eecd7b89e96c3a833f254291/b21bb051f81986187757190942ed2e738bd4e62f.jpg)

>Click the "StageChanged" button to add the file to the temprary storage area of the version library.

![Clone](https://imgsa.baidu.com/exp/w=500/sign=577ff697ce5c1038247ecec28210931c/d4628535e5dde7112ec0b57bafefce1b9d166129.jpg)
- **Commit**
>Input the submit version information, click the "Commit" button to submit the new file. and the GIT library will add the new file.

![Commit](https://imgsa.baidu.com/exp/w=500/sign=66d743b711d8bc3ec60806cab28aa6c8/7c1ed21b0ef41bd5a7381e7959da81cb38db3dd7.jpg)
- **Push and Pull**
> To know what is push and pull, we must know the concept of these.
![](http://images2015.cnblogs.com/blog/1033579/201703/1033579-20170317195044479-1524873296.png)

*The staging area*:this is where we modify our code every time.

*The local ropository*:it is the plase we pull(拉取) from the remote repository. it is actually a copy of the remote repository.

*The remote repository*:this is the place to store your code on the server. or every one thinks their code is modified so that they can upload it collectively. And you can download other's code from here.

And we can know push and pull now:
>*Pull*:pulling data from the remote repository to the local repository.

>*Push*:commit our code from the staging area to the local repository. and if we need to submit our code to remote server, we need to push code to remote branch.