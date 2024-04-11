import java.lang.AssertionError

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun main(args: Array<String>) {
    var tt = readInt()
    for (qq in 0 until tt) {
        var (n, k) = readInts()
        val s = readLn()
        var topCnt = 0
        var curLevel = 0
        for(c in s) {
            if (c == '(') curLevel++
            else {
                curLevel--
                if (curLevel == 0) topCnt++
            }
        }
        val ans = topCnt + minOf(k, (n - 2 * topCnt) / 2)
        println(ans)
    }
}