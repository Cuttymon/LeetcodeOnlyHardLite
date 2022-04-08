class Solution {
    fun findSubstring(s: String, words: Array<String>): List<Int> {
        if (words.isEmpty() || s.isEmpty()) {
            return listOf()
        }
        val res = mutableListOf<Int>()
        val hashMap = HashMap<String, Int>()
        val len = words[0].length
        val n = s.length
        val m = words.size
        for (word in words) {
            hashMap[word] = hashMap.getOrDefault(word, 0) + 1
        }
        for (i in 0 until len) {
            println("i = $i")
            var cnt = 0
            val copy = HashMap(hashMap)
            println("hashMap = $hashMap")
            var j = i
            while (j <= n - len) {
                val sub: String = s.substring(j, j + len)
                println("sub = $sub")
                copy[sub] = copy.getOrDefault(sub, 0) - 1
                if (copy[sub]!! >= 0)
                    cnt++
                val popStart = j - m * len
                println("popStart = $popStart")
                if (popStart >= 0) {
                    val pop: String = s.substring(popStart, popStart + len)
                    copy[pop] = copy.getOrDefault(pop, 0) + 1
                    if (copy[pop]!! > 0)
                        cnt--
                }
                if (cnt == m) {
                    res.add(popStart + len)
                }
                j += len
            }
        }
        return res
    }
}