
# Zotero WPS 插件

这是一个运行在WPS Office 上的 COM 插件，用于衔接 WPS 和 Zotero 软件。事实上，这个插件利用了 [Zotero Word](https://github.com/zotero/zotero-word-for-windows-integration) 插件的功能。Word 插件运行在Zotero进程内，使用 COM API 操作 Word 文档。Word 进程通过 Zotero.dotm 的 VBA 宏同 Zotero 进程通信。

WPS Office 支持 COM API，但是其个人版的安装包中不带有VBA功能，所以在加载了 Zotero.dotm 文件后仍然无法同 Zotero 软件协作。

本插件用于替代 Zotero.dotm 文件，将用户输入和文档信息通过 Windows 窗口消息传递 Zotero 进程，让WPS能正常使用 Zotero 软件。

## 适用范围

只推荐在 WPS Office 个人版上使用。WPS Office 企业版带有VBA功能，只需要加载官方的Zotero.dotm即可。

另外，安装后在 Microsoft Word 32位版本上也会看到本插件的选项卡，介意的话请慎重。

## 安装方法

1. 下载编译好的压缩包，解压到一个合适的目录，例如（D:\ZoteroWps）。
2. 运行解压目录内的 ZoteroWps_WL.reg 文件，将插件注册进WPS的插件白名单内。
3. 运行WPS，进入文字组件界面。找到“开发工具”选项卡，点击“COM 加载项”。
4. 在 COM 加载项界面上，点击“添加”按钮，选择前面已解压好的 “ZoteroWps.dll”，点“打开”。
5. 确保列表框内的 “ZoteroAddin.Connect”项被勾选，点“确定”。
6. 一切正常的话，就能看到 “Zotero WPS” 选项卡了。

## 编译

1. 需要安装 VS2019 以上版本，以及 Windows SDK。
2. 安装好 WPS Office， 并找到其程序文件安装路径。
3. 打开 pch.h 文件，将里面的WPS安装路径改为您本机的WPS安装路径。
4. 用VS打开 ZoteroWps.sln，在项目属性中根据VS版本选择平台工具集，启动编译x86版本即可。

## 其他

[Zotero 官网](https://www.zotero.org/)

