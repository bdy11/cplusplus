1. 文件/目录操作

命令	                      作用
ls	                        列出当前目录内容（ls -l 显示详细信息）
cd dir	                    进入目录
pwd	                        显示当前路径
mkdir dir	                  创建目录
rm file	                    删除文件（-r 递归删除，-f 强制）
cp src dst	                复制文件/目录（-r 递归复制目录）
mv src dst	                移动或重命名文件/目录
touch file	                创建空文件或更新时间戳
find /path -name "*.txt"	  查找文件
tree	                      树状结构查看目录（需安装）

2. 查看/编辑文件

命令	作用
cat file	显示文件内容
less file	分页查看（上下翻页）
head -n 10 file	查看前 10 行
tail -n 20 file	查看最后 20 行
tail -f logfile	实时查看日志更新
nano file	简单编辑器（快捷）
vim file	强大的编辑器（有点学习曲线）

 3. 权限与归属

命令	作用
chmod 755 file	修改权限
chown user file	修改所有者
chgrp group file	修改所属组
ls -l	查看权限与所有者

4. 进程与资源

命令	作用
top / htop	实时系统资源监控
ps aux	查看所有进程
kill PID	终止进程
kill -9 PID	强制终止进程
free -h	查看内存使用情况
df -h	查看磁盘空间
du -sh dir	查看目录大小
uptime	查看运行时长和负载
lsof -i	查看端口和网络连接使用情况

5. 网络命令

命令	作用
ping host	测试连通性
ifconfig / ip a	查看网络接口信息
curl url	获取网页或接口数据
wget url	下载文件
netstat -tulnp	查看端口监听状态（或用 ss）
ssh user@host	远程登录服务器

6. 压缩/打包

命令	作用
tar -czvf file.tar.gz dir/	压缩目录
tar -xzvf file.tar.gz	解压 tar.gz 文件
zip -r file.zip dir/	压缩 zip
unzip file.zip	解压 zip

7. 用户和权限管理

命令	作用
adduser name	添加用户
passwd name	修改密码
su	切换用户
sudo command	以管理员权限运行命令
groups name	查看用户所属组

 8. 系统管理与服务

命令	作用
reboot	重启系统
shutdown now	立刻关机
systemctl status service	查看服务状态
systemctl start service	启动服务
systemctl stop service	停止服务
systemctl enable service	开机启动
journalctl -u service	查看服务日志