/**
 * Do some preparatory works for learning next chapter.
 */
const fs = require('fs')
const {
  chapterNames,
  exampleDirName,
  imagesDirName,
} = require('./constant')
const {
  getChapterDirs,
  resolve,
} = require('./utils')
 
main()

function main() {
  const chaptersAlreadyLearned = getChapterDirs()
  const chaptersNotLearned = chapterNames.filter(chapter => !chaptersAlreadyLearned.includes(chapter))
  const nextChapter = chaptersNotLearned[0]
  if (!nextChapter) return console.log('Congratulations, you have already learned all chapters!')
  fs.mkdirSync(resolve(nextChapter)) // make root dir of next chapter
  fs.mkdirSync(resolve(nextChapter, exampleDirName)) // make example dir of next chapter
  fs.mkdirSync(resolve(nextChapter, imagesDirName)) // make images dir of next chapter
  fs.writeFileSync(resolve(nextChapter, 'README.md'), `# ${nextChapter}\n\n`)// generate READMD.md
}
