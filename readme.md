所有csp和leetcode的代码
关于使用git提交文件到github
https://blog.csdn.net/u011332271/article/details/105320697
1、git bash打开之后cd到目标文件
2、git init 初始化一个空的git仓库
3、git add . 将本地文件都添加到仓库缓存中
4、touch .gitignore #如果你想忽略一些文件或者文件夹，在本地同级目录创建.gitignore文件，在文件中输入你要忽略的文件或者文件夹即可

<!-- 上方可以用vscode实现或者 -->
5、git commit -m '注释'
6、git remote add origin https://github.com/hhh-2086/csp-leetcode #仓库链接地址
7、git push -u origin master #master是提交的分支，将代码提交到github的操作

<!-- 取消http代理 -->
git config --global --unset http.proxy//取消http代理
git config --global --unset https.proxy//取消https代理 

直接用vscode可以解决所有push问题
