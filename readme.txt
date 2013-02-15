将include文件夹和三个h文件放在工程目录下，调用get.h即可
libmysql.dll和编译的exe放在一起
在main中调用get()函数，即可获得id，type，title，announce，indate，post_date六个数据，记录在result_row里
result_row[0]   id自动递增且唯一
result_row[1]   type为预留项，暂时无用
result_row[2]   title为通知的标题，为gbk编码的中文字符串
result_row[3]   announce为通知的内容，为gbk编码的中文字符串
result_row[4]   indate为通知有效期，格式形如如2013-01-01 12:00
result_row[5]   post_date为通知发布日期，格式形如如2013-01-01 12:00
