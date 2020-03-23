const {
  genLink,
}  = require('./utils')
const bookName = '大话数据结构'
exports.exampleDirName = 'example'
exports.imagesDirName = 'images'

exports.chapterNames = [
  '第一章-数据结构绪论',
  '第二章-算法',
  '第三章-线性表',
  '第四章-栈与队列',
  '第五章-串',
  '第六章-树',
  '第七章-图',
  '第八章-查找',
  '第九章-排序',
]

exports.HEADER = `
# 《${bookName}》学习笔记

![Cover](${genLink('cover.jpg')})

`
