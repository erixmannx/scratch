import scala.collection.immutable.Seq
import scala.util.Random

object Quicksort {
	def swap(items : Seq[Int], i1 : Int, i2 : Int) : Seq[Int] = {
		val t = items(i1)
		var scratch = items.updated(i1, items(i2))
		scratch.updated(i2, t)	
	}

	def quicksort(items : Seq[Int], low : Int, high : Int) : Seq[Int] = {
		def partition(items : Seq[Int], low : Int, high : Int) : (Seq[Int], Int) = {
			var scratch = items

			val pivot = items(high)
			var i = low - 1

			for (j <- low to high - 1) {
				if (scratch(j) < pivot) {
					i += 1
					scratch = swap(scratch, i, j)
				}
			}

			scratch = swap(scratch, i + 1, high)
			(scratch, i + 1)
		}

		if (low < high) {
			val tup = partition(items, low, high)
			var scratch = tup._1
			val p = tup._2
			scratch = quicksort(scratch, low, p - 1)
			quicksort(scratch, p + 1, high)
		} else {
			items
		}
	}

	def sortSeq(items : Seq[Int]) : Seq[Int] = {
		quicksort(items, 0, items.length - 1)
        }

	def createSeq(size : Int) : Seq[Int] = {
		Seq.fill(size)(Random.nextInt % 100)
	}

	def printSeq(items : Seq[Int]) = {
		items.foreach(str => print(s"$str "))
	}

	def main(args : Array[String]) : Unit = {
		println("Hello")

		val items = createSeq(100)
//		printSeq(items)

		val sorted = sortSeq(items)

		printSeq(sorted)
	}
}
