mode	Mode可以是以下几个值之一：



textareas - 页面加载时把所有TEXTAREA组件转换成编辑器.

specific_textareas - 将所有"mce_editable"属性值为true的TEXTAREA转换成编辑器.

exact - 只转换在"elements"设置中指定的确切组件.
[theme]	指定要使用的主题名称，主题将被放在TinyMCE的themes目录下，默认为default。TinyMCE自带三个内置的主题，它们是simple，default和advanced。

如果你想创建自己的主题，请仔细阅读文档的 主题 部分。
[plugins]	此选项是一系列以逗号分隔的主题插件列表（例如，可以只用来扩展图像对话框）。这些插件覆盖了主题模板中定义的功能。插件逻辑应该包含在一个叫"editor_plugin.js"的文件中，它是插件目录中唯一被包含进来的文件。

例如："my_image_dialog,my_link_dialog". 

如果你想创建自己的插件，请仔细阅读文档的 主题 部分。
[language]	TinyMCE中使用的语言包，这应该是像se,uk,us等诸如此类的FN代码，它被用来从"langs"目录中获取语言包，该设置的默认值为"uk".

中文用户建议您使用"zh-CN"
[elements]	以逗号分隔的用来转换成编辑器的组件列表，该选项仅在"mode"选项被设置成"exact"时使用。该列表中的元素可以是任何有id或name属性的HTML组件。
[ask]	当"mode"被设置成"textareas"或"specific_textareas"的时候，该选项被应用，询问用户输入框是否将被转换成编辑器。 

如果你想使用这个选项，将它设置为true.
[textarea_trigger]	textarea（文本域）触发器的属性，默认值为"mce_editable"。

该选项仅在"mode"被设置为"specific_textareas"时使用。
[valid_elements]	以逗号分隔开的组件转换部分的列表。



例如： a[href|target=_blank],strong/b,div[align],br.



以上例子告诉TinyMCE移除所有除了"a, strong, div"和"br"的组件，将元素b转换成strong，默认target设为"_blank"并保持href、target、align属性。在匹配组件及属性的名称时可以使用像*,+,?这样的通配符。



字符：

,	各组件定义之间的分隔符。
/	两个同义组件之间的分隔符。第一个组件是会被用来输出的那个（即第二个组件被第一个替换）。
|	各属性定义之间的分隔符。
[	定义某组件的属性列表的开始符号。
]	定义某组件的属性列表的结束符号。
=	将属性的默认值设为特定值。例如："target=_blank"
:	将属性的值强行设为特定值。例如："border:0"
<	校验某个属性的值。例如："target<_blank?_self"
?	属性校验值之间的分隔符，见上。

特殊变量：

{$uid} - 产生一个唯一ID号。 例如："p[id:{$uid}]".



此选项的默认值是以下模式：

"a[href|target],strong/b[class],em/i[class],strike[class],u[class],p[class|align],ol,ul,li,br,

img[class|src|border=0|alt|hspace|vspace|width|height|align],sub,sup,blockquote[dir|style],

table[border=0|cellspacing|cellpadding|width|height|class|align],tr[rowspan],

td[colspan|rowspan|width|height],div[class|align],span[class|align],pre[class|align],

address[class|align],h1[class|align],h2[class|align],h3[class|align],

h4[class|align],h5[class|align],h6[class|align],hr".



要包含所有组件及属性，请使用 *[*] ，这在使用invalid_elements选项时特别有用。
[extended_valid_elements]	向"valid_elements"列表末尾添加可用组件。此选项在你仅仅想往默认列表中增添部分组件时相当有用。

格式与"valid_elements"一致。
[invalid_elements]	输出时需要排除在外的组件名称列表，以逗号分隔开。
[trim_span_elements]	True/False选项。如果设置为true，不需要的组件将被移除。默认值即为true。
[verify_css_classes]	True/False选项。如果设置为true，将会校验CSS的class属性。默认值即为true。
[verify_html]	True/False选项。代表着HTML内容是否需要校验。默认值为true。
[urlconvertor_callback]	当清理进程处理URL的时候调用的函数名。此函数必须遵从以下的格式：func(url, node, on_save) ，返回转换后的URL。此设置专为集成目的而设。参数url代表要转换的地址，node代表包含URL的那个节点，on_save是一个布尔值（在用户提交表单时为真）。
[preformatted]	True/False选项。如果设置为true，编辑器将把制表符（TAB）转换成缩进，除此外保持其他whitespace（空白字符、换行等）字符，就如同HTML标签中的PRE的效果。默认值为false。
[insertlink_callback]	当执行"insertlink"命令时调用的函数名。此函数获取选定链接的地址和目标，返回一个以"href", "target"和 "title"为collection名称的数组。当使用新窗口时，为了兼容Mozilla，会在window.opener（弹出窗口的母窗口，译者注）上调用tinyMCE.insertLink。
[insertimage_callback]	当执行"insertimage"命令时调用的函数名。此函数获取选定图像的url并返回一个以src和alt为collection名称的数组。当使用新窗口时，为了兼容Mozilla，会在window.opener上调用tinyMCE.insertImage。

函数格式：insertimage(src, alt, border, hspace, vspace, width, height, align, title, onmouseover, onmouseout, action).
[setupcontent_callback]	当编辑器初始化时调用的函数名。函数格式：setupContentCallback(editor_id, node)，其中editor_id是编辑器的id，node是编辑器所在的body组件节点。
[save_callback]	当执行triggerSave（触发保存）命令被调用时调用的函数名。函数格式：save(id, content, node)，如果有特定返回值，其值将会被加到HTML表单组件上。所以可以通过此函数来自定义用户转换逻辑。
[docs_language]	TinyMCE文档中使用的语言，这应该是像se,uk,us等诸如此类的FN代码，它被用来从"<theme>/docs/<lang>"目录中获取文档。 该选项的默认值跟language选项一致。
[width]	编辑器的宽度，它默认的宽度是原先被替换的组件宽度。
[height]	编辑器的高度，它默认的高度是原先被替换的组件高度。
[content_css]	编辑窗口中要使用的CSS文件，其路径应该跟页面相关。
[popups_css]	像插入链接和图片时的弹出窗口中使用的CSS文件，其路径应该跟页面相关。
[editor_css]	编辑器使用的CSS文件，其路径应该跟页面相关。
[encoding]	编辑器的输出编码，此选项目前只能为"html"或者空。如果设置为"html"，编辑器的输出将经过HTML编码处理。

例如：<将会变成&lt;，依此类推。默认值是空。
[debug]	True/False选项。如果设置成true，像css文件路径等调试信息将会被显示。
[visual]	True/False选项。如果设置成true，当边框设置成0的时候，为达到更好的视觉效果在编辑器中表格会有虚线出现。

默认值为true。
[visual_table_style]	用户可自定义表格的样式，默认值为："border: 1px dashed #BBBBBB"。
[add_form_submit_trigger]	True/False选项。如果设置成true，将强制进行所有表单的"onsubmit"事件处理并引发保存。此选项默认值为true。
[add_unload_trigger]	True/False选项。如果设置成true，在"onunload"事件发生时，当前窗口会引发一个triggerSave调用。此triggerSave调用不会做任何清理工作，因为它是用来处理 前进/后退 按钮的。此选项默认值为true。
[force_br_newlines]	True/False选项。此选项强制编辑器将段落符号(P)替换成换行符(BR)。此选项默认值为false。（实验阶段）
[force_p_newlines]	True/False选项。如果打开此选项，在按下回车键（Enter）时Mozilla/Firefox浏览器会生成段落符号(P)，在按下Shift+Enter时会生成换行符(BR)。此选项默认为true。
[relative_urls]	True/False选项。如果设置成true，绝对路径将被转换成相对路径。默认值为true。
[remove_script_host]	True/False选项。在设置成true的情况下，如果URL中的主机名、端口号跟编辑器当前所在一致，它们会被移除。

例如：编辑器所在站点为 http://www.somesite.com ，那么以下链接 http://www.somesite.com/somedir/somepage.html 将会被转换成 /somedir/somepage.html 。

如果relative_urls被设置成false，此选项默认为true。
[focus_alert]	True/False选项。如果设置成true，编辑器在失去焦点的时候就会出现一个烦人的警告框。默认值为true。
[document_base_url]	在将绝对路径转换成相对路径的时候会用到此文档的URL。这个选项指定了编辑器当前的默认文档。

注意如果此选项指定到一个域名，请添加协议前缀，并以斜杠结尾。例如：http://www.somehost.com/mydir/
[custom_undo_redo]	True/False选项。此选项可以使 撤消/重做 功能更加完善。默认值为true。
[custom_undo_redo_levels]	自定义最多可撤消操作的次数，默认是无限制。
[custom_undo_redo_keyboard_shortcuts]	如果使用，编辑器可以使用Ctrl+Z和Ctrl+Y快捷键来实现撤消和重做。默认允许。
[fix_content_duplication]	True/False选项。此选项修正了MSIE中一个内容重复的bug。默认启用，但是为了兼容性也可以禁用(false)。
[directionality]	此选项可以设置像阿拉伯语等语言的文字方向。可能的值为：ltr, rtl。默认值: ltr（从左到右）。
[auto_cleanup_word]	如果启用，从MS office/Word粘贴的HTML将会自动被清理。此选项默认值为false。

注意：此操作当前仅支持MSIE。
[cleanup_on_startup]	如果启用，在编辑器初始化时文本域及组件将会被清理。默认值为false。
[inline_styles]	如果启用，像width,height,vspace,hspace和align等属性将会被风格属性替代。默认值为false。

在使用此选项时记得要把风格属性应用在正确的组件上。
[convert_newlines_to_brs]	如果启用，所有的\n(新行)将会在编辑器启动时被转换成<br />组件。此选项默认值为false。
[auto_reset_designmode]	因为在调用style.display的none/block方法来显示/隐藏某个TinyMCE编辑器的时候有bug，设计模式需要被重置。此选项一旦启用，当编辑器聚焦时，将自动重置。默认值为false。
[entities]	一张以字符代码来查找名称的表，该表中元素是以逗号分隔开的实体列表。该列表以奇数项、偶数项区分，其中奇数项是被用来转换的字符代码，偶数项是代表那个字符代码的实体名称。例如："8205,zwj,8206,lrm,8207,rlm,173,shy"。
[cleanup_callback]	自定义清理函数。此选项能让用户在默认的清理基础上有所扩展。此函数调用跟默认的调用是分开的，它并不替换默认的清理函数，而仅仅是扩展。点击 插件清理 查看更多细节。
主题的高级特定设置
[theme_advanced_toolbar_location]	此选项用来改变工具栏的默认位置。可能的值为："top"和"bottom"。默认值是"bottom"。
[theme_advanced_toolbar_align]	此选项用来设置工具栏的对齐方式是left, center还是right。默认值是center。
[theme_advanced_styles]	此选项可以用来增加风格下拉框中的CSS类和名称。格式如下："<title>=<class>;.."。

如果没有指定此选项，主内容部分的CSS类将会被自动导入。

例如："Header 1=header1;Header 2=header2;Header 3=header3"
[theme_advanced_buttons1]	工具栏上第一行要包含的按钮列表，以逗号分隔开。例如："bold,italic,underline"。



允许的按钮名称如下：

bold, italic, underline, strikethrough, justifyleft, justifycenter, justifyright, justifyfull, styleselect, bullist, numlist, outdent, indent, undo,redo, link, unlink, image, cleanup, help, code, table, row_before, row_after, delete_row, separator, rowseparator, col_before, col_after, delete_col, hr, removeformat, sub, sup, formatselect, fontselect, fontsizeselect, forecolor,charmap,visualaid,spacer,cut,copy,paste
[theme_advanced_buttons2]	同上，差别在于指定的是工具栏第二行。
[theme_advanced_buttons3]	同上，差别在于指定的是工具栏第三行。
[theme_advanced_buttons<N>_add]	向工具栏上特定的第N行中增加额外的控制/按钮。例如：theme_advaned_buttons3_add : "iespell".
[theme_advanced_buttons<N>_add_before]	向工具栏上特定的第N行的默认按钮前面增加额外的控制/按钮。例如：theme_advaned_buttons3_add_before : "iespell"。
[theme_advanced_disable]	要禁用的按钮/组件的列表，以逗号分隔。例如："formatselect".
[theme_advanced_source_editor_width]	源文件编辑器窗口的宽度。
[theme_advanced_source_editor_height]	源文件编辑器窗口的高度。
[theme_advanced_path_location]	组件路径列表的位置，可能的值为："top"或"bottom"。默认值为："none"
[theme_advanced_blockformats]	formatselect列表要屏蔽的格式列表，以逗号分隔开。默认值：p,address,pre,h1,h2,h3,h4,h5,h6。