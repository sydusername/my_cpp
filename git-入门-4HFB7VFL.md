---
tags:
    - git入门
parent: ""
collections:
    - git
version: 0
libraryID: 1
itemKey: 4HFB7VFL

---
# git 入门

参考视频教程

    https://www.bilibili.com/video/BV1HM411377j?p=1&vd_source=9d800611b62cbf1282fcc9e8602e99a3

## 版本控制系统分类

### 集中式 svn

*   所有文件保存在服务器上，个人电脑只有副本
*   修改文件流程：先从服务器上下载，修改完再提交服务器
*   优点：操作简单
*   缺点：中央服务器出现故障或有网络问题时，所有人都无法工作了

### 分布式git

*   每个人的电脑上都有一个完整的版本库，直接在本地上修改，然后将仓库互相同步

## 本地使用方式

*   GUI
*   IDE扩展
*   命令行：常用方式，下面介绍此方式

### 1. 配置用户名和邮箱

1.  识别是谁提交的代码，只需要在最开始配置一次

        git config --global user.name "sun_yd"

    <!---->

        git config --global user.email 邮箱地址

    1.  \--global全局配置，对所有仓库有效
    2.  \--system：系统配置，对所有用户生效
    3.  省略（Local）：本地配置，只对本地仓库有效

2.  查看配置信息

        git config --global --list

### 2.创建仓库

1.  本地创建仓库

        git init

    1.  linux环境下

            mkdir learn-git //创建一个文件夹

        <!---->

            cd learn-git //转到文件夹目录下

        <!---->

            ls -a //查看当前目录下的所有文件，包括隐藏文件 .git就在里面

        <!---->

            \rm -rf .git //删除.git文件夹

        <!---->

            git init my-repo //新建一个文件夹，并在文件夹里创建git目录

2.  从远程服务器克隆一个已经存在的仓库

        git clone 仓库地址

### 3.工作区域和工作状态

*   工作区域：

1.  工作区： 本地目录，资源管理器看到的目录，相当于生产车间

        git add .  //将要修改的（文件）打包到卡车上（暂存区）

2.  暂存区：索引，保存即将提交到git仓库的修改内容，临时区域，相当于卡车

3.  本地仓库区：通过git init创建的那个仓库，包含了完整的项目历史和元数据，相当于工厂仓库，版本库

*   工作状态：

1.  未跟踪：新创建的，还没有被git管理的文件
2.  未修改：已经被git管理起来，但是内容没有变化
3.  已修改：已经修改过的文件，还没有添加到暂存区里
4.  已暂存：已经修改，并且添加到暂存区的文件

![\<img alt="" data-attachment-key="LBUU2DGW" width="1055" height="500" src="attachments/LBUU2DGW.png" ztype="zimage">](attachments/LBUU2DGW.png)

### 4.添加和提交文件

*   查看仓库状态

        git status  //比如当前处在哪个分支，有哪些文件，以及文件处在什么状态

    <!---->

        git ls-files  //查看暂存区的文件

    <!---->

        ls //查看工作区文件，即当前文件夹里的内容

*   Linux创建文件，此时文件status为untrack

        echo "Hello, World!" > file1.txt  //将内容“Hello, World!”输出到file1.txt文件中    >> file1.txt表示追加

    <!---->

        cat file1.text  //查看文件内容

    <!---->

        mv file.txt file4.txt  //修改文件名字为file4.txt

    <!---->

        cp -rf 源文件(夹） 目标文件 （夹）  //复制

*   将文件添加到暂存区，状态为staged

        git add file1.txt  //添加文件file1.txt

    <!---->

        git add .  //表示添加当前目录下所有的文件，包括子目录

    <!---->

        git add *.txt  //表示添加当前目录下所有后缀名为.txt的文件

    *   撤回暂存区的文件，回到工作区

            git rm file1.txt

*   把暂存区的文件提交到本地仓库，不会提交工作区的文件

        git commit -m "第一次提交”

*   针对修改的文件，可以同时暂存和提交

        git commit -a -m "提交信息"

*   查看提交记录

        git log

    <!---->

        git log --online  //查看简洁的提交信息

### 5.回退版本

    git reset --soft  版本号     //回退到某一个版本（清空仓库的版本），保留工作区，保留暂存区。回退版本后，修改再提交

<!---->

    git reset --hard  版本号     //回退到某一个版本（清空仓库的版本），丢弃工作区，丢弃暂存区

<!---->

    git reset --mixed(默认）版本号//回退到某一个版本（清空仓库的版本），保留工作区，丢弃暂存区

*   放弃本地修改，用hard模式

*   当连续提交了多个版本，又觉得没什么太大意义，可以回退版本再重新提交，合并成一个版本

    *   soft模式需要重新添加到暂存区git add .
    *   mixed则不需要

### 6.回溯操作

1.      git reflog  //查看历史记录
2.  找到误操作之前的版本号
3.      git reset --hard 版本号 //回退到某个版本

### 7.查看差异

第一行：发生变更的文件

第二行：git会将文件的内容使用哈希算法生成一个40位的哈希值，后面是文件的权限

下面2行表示修改的文件

-表示原来的内容

+表示修改后的内容

    git diff  //默认比较工作区和暂存区的变化

<!---->

    git diff HEAD   //比较工作区+暂存区和版本库的差异，      不确定

<!---->

    git diff --cached  //暂存区和版本库的差异

<!---->

    git diff <commit_hash> <commit_hash>  //比较2个版本之间的差异
    git diff HEAD~ HEAD   //表示当前版本和上个版本的差异     
    HEAD^也可以表示上个版本
    HEAD~2表示前2个版本
    git diff <commit_hash> <commit_hash>  fiel3.txt  //只查看fiel3.txt的差异

<!---->

    git diff <branch_name> <branch_name> //比较分支之间的差异

### 8.从版本库删除文件

1.  直接在工作区删除文件，提交暂存区，再提交到工作区，就删除了

        rm file1.txt  //删除文件

2.  把文件从工作区和暂存区中删除，再提交

    1.      git rm file1.txt  
    2.      git commit -m "名称"

3.      git rm --cached file1.txt  //从暂存区删除文件

4.      git rm -r *  //递归删除某个目录下的所有子目录和文件

### 9..gitignore

*   应该忽略的文件

    *   系统或者软件自动生成的文件
    *   编译生成的中间文件和结果文件
    *   运行过程中生成的日志文件、缓存文件、临时文件
    *   设计身份、密码、口令、密钥等敏感信息文件

*   注意：.gitignore文件生效的前提是 这个文件不能是已经添加到版本库的文件

*   创建编辑文件

        echo "other log" >access.log   //创建日志文件

    <!---->

        echo access.log >.gitignore   //将日志文件添加到.gitignore 文件

    <!---->

        vi .gitignore  //vi编辑文件
        按esc 再 :wq保存文件并退出vi 编辑

*   常用格式<[ .gitignore 模板集合](https://github.com/github/gitignore)>

        *.log   //所有以.log结尾的文件

    <!---->

        temp/   //忽略temp文件夹，空文件夹不会被添加

glob匹配，图片有误

![\<img alt="" data-attachment-key="6CBK9K77" width="1052" height="386" src="attachments/6CBK9K77.png" ztype="zimage">](attachments/6CBK9K77.png)

![\<img alt="" data-attachment-key="Z525E8IH" width="910" height="619" src="attachments/Z525E8IH.png" ztype="zimage">](attachments/Z525E8IH.png)

## 远程使用方式

### SSH推送

*   HTTPS：每次提交需要验证账户和密码，已停用

*   SSH配置：推荐方式，提前在GitHub上设置ssh密钥，每次推送不需要验证账户和密码

    1.      cd   //回到根目录

    2.      cd .shh  //跳转到.shh目录

    3.      ssh-keygen -t rsa   //生成ssh文件，协议为rsa,若已有ssh文件，选no，可以选择密码为空

    4.  网上搜索github配置ssh

    5.  多个ssh文件，指定用哪个文件

            # github

        <!---->

            Host github.com

        <!---->

            HostName github.name

        <!---->

            PreferredAuthentications publickey

        <!---->

            IdentityFile ~/.ssh/test

*       git push <remote><branch>   //推送更新内容

*       git pull <remote>  //拉取更新内容

### 关联本地仓库和远程仓库

1.      git remote add origin git@github....   //添加远程仓库,别名（名称）为origin

2.      git remote -v  //查看对应的远程仓库和地址

3.      git branch -M main  //指定分支为main

4.      git push -u origin main:main   //将本地main推送到远程main，如果名称相同，可以只写一个

5.      git pull <远程仓库名><远程分支名> : <本地分支名>   //将远程仓库拉取到本地

    1.  远程可以不写，默认origin main
    2.  git pull会默认执行一次合并操作，如果远程本地没有冲突，可以合并
    3.      git fetch //从远程拉取到本地，但不会执行合并操作，需要手动合并
    4.  跳转到分支部分处理

## 分支

*   可以看作代码库中不同版本，可以独立存在，并有自己的提交记录
*   多个开发人员可以在自己的分支工作，最后在合并到主线
*   可以在一个分支上进行新功能的开发，beat版
*   可以建立一个问题修复的分支来处理一些bug和缺陷
*   保证主干上是稳定版本

### 创建/查看/切换/合并/删除分支

1.      git branch <分支名>   //创建分支

2.      git banch   //查看分支列表，当前分支前有*

3.      git switch <分支名>  //切换分支

    <!---->

        git chechout <分支名>   //切换分支,还可以恢复文件，有歧义，不用

4.      git merge <分支名>  //将分支合并到当前分支，结合git switch用，会默认产生一次提交，需要写提交信息

5.      git log --graph --online --decorate --all  //查看分支合并过程

    <!---->

        alias <别名> ="git log --graph --online --decorate --all"   //给较长的命令设置别名

6.      git branch -d <分支名>  //删除已经合并后的分支

7.      git branch -D <分支名>  //强制删除分支（未合并的）

### 合并冲突

在git merge <分支名> 合并后，发现有冲突（修改了同一文件的同一位置）

1.      git status  //查看合并冲突的文件

2.      git diff  --all //查看冲突的具体内容

    \= 表示2个分支冲突的分界线

3.  直接打开冲突的文件，进行编辑

4.      git commit -a -m ""  //提交后自动完成合并

5.      git merge --abort  //中断合并

### 回退和rebase

执行过程

1.  找到分支的共同祖先main3
2.  （在dev分支操作）找到main分支最新提交记录main5
3.  将dev分支移动到main5，如左图所示

![\<img alt="" data-attachment-key="LM5WQ6Z4" width="1509" height="850" src="attachments/LM5WQ6Z4.png" ztype="zimage">](attachments/LM5WQ6Z4.png)

### merge与rebase区别

*   merge优点：不会破坏原分支的提交历史，方便回溯和查看
*   merge缺点：会产生额外的提交节点，分支图比较复杂
*   rebase优点：不会新增额外的提交记录，形成线性历史，比较干净和直观
*   rebase缺点：改变了提交历史和当前分支的branch out节点，应避免在共享分支中使用

## 工作流模型

GitFlow：团队水平适中，有一定的开发流程和规范的团队

![\<img alt="" data-attachment-key="WW56CZZU" width="1449" height="770" src="attachments/WW56CZZU.png" ztype="zimage">](attachments/WW56CZZU.png)

*   主分支：稳定版本，经过测试和审核，只能通过合并分支的方式修改，v1.0.0

    *   主版本：主要功能或重大更新
    *   次版本：新功能，通常不会影响现有功能
    *   修订版本：bug修复
    *       git tag <标签名> <提交ID>   //给提交设置标签
    *       git push origin --tags   //推送所有本地标签

*   热修复版本：紧急修复主分支上的bug，修复后，合并到主分支并删除，更新小版本号

*   发布版本：准备项目发布，稳定后合并到主分支和开发分支

*   开发版本：日常开发，长期存在

*   功能版本：新功能，合并到开发版本

GitHubFlow：团队水平较高的团队或者开源项目

*   只有一个长期存在的主分支，可以直接部署到生产环境中的，会设置分支保护，禁止团队成员直接在主分支上进行提交
*   团队成员会在主分支上分离出自己的分支，然后在本地分支提交代码
*   开发完成后发起一个pull request（合并请求）
*   团队成员进行代码评审，没有问题后合并到主分支

分支命名技巧：带有意义的描述性名称来命名分支

*   版本发布分支：v1.0.0
*   功能分支：feature-login-page   //功能-登录-界面
*   修复分支：hotfix-#issueid-desc

分支管理技巧：

*   定期合并已经成功验证的分支，及时删除已经合并的分支
*   保持合适的分支数量
*   为分支设置合适的管理权限

## gitee国内平台和gitlab私有化部署

*   gitee国内平台
*   gitlab私有化部署

## vscode侧边栏

将常用功能集成到侧边栏了
