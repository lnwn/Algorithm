## 1. namespace两种声明方式

1.FirstClass属于firstnamespace的命名空间

```markdown
namespace firstnamespace;
class FirstClass{
  	  
}
```

2.SecondClass属于secondnamespace的命名空间

```markdown
namespace secondnamespace{
class SecondClass{
  	 	
}
};
```
**末尾的分号可以不加**

## 2. 删除历史提交记录并保留最新版本

代码 | 说明
------------ | -------------
1. git clone [URL] | 将远程仓库克隆到本地
2. cd [仓库名] | 进入本地仓库
3. git checkout --orphan [new branch] | 创建一个新的空分支
4. git add -A | 添加所有文件到新分支
5. git commit -am '提交信息' | 提交新分支
6. git branch -D master | 删除master分支
7. git branch -m master | 将当前新分支重命名为master
8. git push origin master --force | 将更改推送至远程仓库

**对于团队合作来说该操作需谨慎**

