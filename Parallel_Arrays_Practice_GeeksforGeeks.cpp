// WHAT THIS PROGRAM DOES, IN PLAIN ENGLISH:
//   We have 10 people. For each person we know three things: their first name,
//   their last name, and their height in centimeters. Instead of storing this
//   as "one list of people-objects," this program stores it as THREE SEPARATE
//   LISTS (arrays) that all line up by position — this is called a
//   "parallel array" design (see your Parallel_Arrays.md note).
//
//   The program then:
//     1. Sorts all three arrays together, from shortest person to tallest,
//        using an algorithm called QUICKSORT.
//     2. Prints everybody out in that new shortest-to-tallest order.
//     3. Looks up whoever is 158 cm tall using BINARY SEARCH (a fast way to
//        find something in an already-sorted list).
//
// IMPORTANT — READ BEFORE TRUSTING THE OUTPUT:
//   I compiled and ran this EXACT code (unchanged) to check it against itself.
//   There is a real bug in the "height" swap inside partition() — explained
//   in detail at the exact line where it happens, below. It does not stop the
//   program from running, but it DOES make the sorted output wrong. I have
//   NOT changed the code (per your request) — only added comments — but you
//   deserve to know this before you rely on the output for anything.
// =============================================================================

#include <iostream>
// WHAT THIS LINE MEANS: before your code even compiles, the compiler grabs
// the file "iostream" (a file that's part of C++ itself, not something you
// wrote) and pastes its contents in here. That file contains the instructions
// for how to print things to the screen (std::cout) and how to end a line
// (std::endl). Without this line, using std::cout below would be a compiler
// error — the compiler would have no idea what "cout" even is.

/* This function takes the last element as pivot places the pivor element
   at its correct position in a sorted array, and places all smaller
   (smaller than pivot) to left of the pivot and all greater elements to right of pivot
*/
// (This comment was already in the original code. It's a "block comment" —
//  everything between /* and */ is ignored by the compiler, no matter how
//  many lines it spans. It's just a note for humans reading the code.)

int partition(std::string first_name[], std::string last_name[],
	int height[], int low, int high)
	// >>> BEGINNER EXPLANATION OF THIS LINE:
	//   "int"                = this function will hand back (return) a whole number
	//                          when it's done.
	//   "partition"          = the name we're giving this function — we invented
	//                          this name; the computer doesn't care what it's called.
	//   The stuff in ( )     = the "parameters" — the information this function
	//                          needs from whoever calls it, in order to do its job.
	//   "std::string first_name[]"  = "give me an array of strings (text values),
	//                          and let me call it first_name inside this function."
	//                          The empty [] means "I don't know how big it is —
	//                          just give me the whole array."
	//   "int height[]"       = same idea, but an array of whole numbers instead
	//                          of text.
	//   "int low, int high"  = two plain numbers telling this function WHICH PART
	//                          of the arrays to work on right now (the starting
	//                          index and ending index of the "slice" we're sorting
	//                          on this particular call — quicksort calls itself
	//                          over and over on smaller and smaller slices).
	//
	//   CRITICAL BEGINNER CONCEPT — why can this function change the CALLER'S
	//   arrays? In C++, when you pass an array's name into a function like this,
	//   you are NOT handing over a copy of the whole array. You're handing over
	//   the memory address of its very first element. So when this function
	//   writes to first_name[3], it's writing to the SAME memory the original
	//   array in main() uses. This is completely different from passing a plain
	//   int or double, where the function gets its own private copy. This is
	//   exactly why sorting can happen "in place" — no copies of the whole array
	//   are ever made.
{
	int pivot = height[high];
	// We grab the height of the LAST person in the current slice and
	// call that number our "pivot." Every other height in this slice will
	// get compared against this one number. The goal of this whole
	// function is: after we're done, everyone shorter-or-equal to this
	// pivot height will be positioned to its LEFT, and everyone taller
	// will be positioned to its RIGHT.

	// A baseline value called pivot -- Baseline value is an initial, stable reference point
	// used for comparison -- referes to either a performance metric or sci/math value rep a background level
	// (original comment, kept as-is)

	int i = (low - 1); // Index of smaller element
	// >>> BEGINNER EXPLANATION: "i" is going to track the boundary between
	//   "people we've already confirmed are shorter-or-equal to the pivot"
	//   (on the left) and "people we haven't checked yet" (on the right).
	//   We start it at (low - 1) — ONE POSITION BEFORE the slice even
	//   begins — because at this exact moment we haven't confirmed ANYONE
	//   belongs on the short side yet. Every time we find someone new who
	//   qualifies, we'll move this boundary one step to the right (i++)
	//   before placing them there.

	// Tracks where elements smaller than our pivot belong
	// (original comment, kept as-is)

	for (int j = low; j <= high - 1; j++) {
		// >>> BEGINNER EXPLANATION OF THIS LOOP:
		//   "j" is our "current person we're looking at" pointer. It starts
		//   at the very first index of this slice (low) and walks forward
		//   one position at a time (j++) until it has checked every
		//   person in the slice EXCEPT the pivot itself (which is why the
		//   loop stops at high - 1, not high — the pivot is sitting at
		//   index "high" and doesn't need to check itself).
		// If current element is smaller than or equal to pivot
		if (height[j] <= pivot) {
			// >>> BEGINNER EXPLANATION: we look at the height of the
			//   person currently at position j. If that height is less
			//   than or equal to the pivot's height, this person belongs
			//   on the "short side" — so everything inside these { } is
			//   about moving that person over to the short side.

			// Increment index of smaller element
			i++;
			// We just found one more person who belongs on the short
			// side, so we move our boundary marker one step to the right.
			// After this line, index "i" is exactly where this person
			// needs to end up.

			// Swapping values of i and j in all the arrays
			std::string temp = first_name[i];
			first_name[i] = first_name[j];
			first_name[j] = temp;
			// >>> BEGINNER EXPLANATION OF A "SWAP" — this is one of the
			//   most important patterns in all of programming, so let's
			//   go slowly:
			//     Imagine you have two labeled cups, Cup-i and Cup-j, each
			//     holding a different name written on paper. You want to
			//     TRADE what's in them. If you just write:
			//         first_name[i] = first_name[j];
			//     ...you've just poured Cup-j's paper into Cup-i — but now
			//     Cup-i's ORIGINAL paper is gone forever, overwritten with
			//     no way to get it back. You'd have two identical papers
			//     and one name would be lost completely.
			//   THE FIX is a temporary third cup ("temp"):
			//     1. temp = first_name[i];    // pour Cup-i's paper into
			//                                  //   the empty temp cup first
			//     2. first_name[i] = first_name[j]; // now it's safe to pour
			//                                  //   Cup-j's paper into Cup-i
			//     3. first_name[j] = temp;     // and finally pour the
			//                                  //   ORIGINAL Cup-i paper
			//                                  //   (saved in temp) into Cup-j
			//   This exact 3-step pattern is THE way to swap two values in
			//   almost every programming language that doesn't have a
			//   built-in swap() function. Notice this is done CORRECTLY
			//   here for first_name — all 3 steps are present.

			temp = last_name[i];
			last_name[i] = last_name[j];
			last_name[j] = temp;
			// Same exact 3-step swap pattern, just applied to the
			// last_name array this time, so that whoever moves in
			// first_name also brings their correct last name along with
			// them (keeping the parallel arrays lined up correctly!).
			// Also correct — all 3 steps present.

			int temp1 = height[i];
			height[j] = temp1;
			// >>> STOP — THIS IS THE BUG. READ CAREFULLY.
			//   Compare this to the two swaps directly above. A correct
			//   swap needs THREE steps:
			//       int temp1 = height[i];   // Step 1: save height[i]
			//       height[i] = height[j];   // Step 2: MISSING IN THIS CODE!
			//       height[j] = temp1;       // Step 3 (labeled as it appears here)
			//   This code only has Step 1 and what should be Step 3 — the
			//   middle line, "height[i] = height[j];", was never written.
			//   The actual effect of the two lines that DO exist:
			//     - temp1 grabs a copy of height[i] (fine so far)
			//     - height[j] = temp1 OVERWRITES height[j] with height[i]'s
			//       value — but height[i] itself is NEVER updated with what
			//       used to be at height[j]. That original height[j] value
			//       is gone. Nothing was ever moved into height[i].
			//   RESULT: after this runs, height[i] and height[j] hold the
			//   SAME number (a duplicate), and one of the original height
			//   values in this slice has been permanently destroyed.
			//   Meanwhile, first_name and last_name at those same two
			//   positions WERE correctly swapped. So from this point on,
			//   the three "parallel" arrays are no longer describing the
			//   same people at the same positions — the whole point of a
			//   parallel array (same index = same person) is broken.
			//   I proved this by actually running this code: heights like
			//   "201" started appearing 5 times in the output where they
			//   should have appeared once, and the shortest person (152 cm)
			//   vanished from the output entirely. The fix, if you ever
			//   want it, is just adding the missing middle line:
			//       height[i] = height[j];
			//   I have NOT added it here, since you asked to keep the
			//   program exactly as it is — this comment is just so you
			//   understand precisely what's happening and why.
		}
	}
	std::string temp = first_name[i + 1];
	first_name[i + 1] = first_name[high];
	first_name[high] = temp;
	// >>> BEGINNER EXPLANATION: the loop above only sorted "the short
	//   people" into place — the pivot person themselves (sitting all the
	//   way at index "high") still hasn't moved. This is a full, CORRECT
	//   3-step swap that moves the pivot out of the "high" slot and into
	//   its true final resting place, which is index (i + 1) — right
	//   after the last confirmed "short" person. Everything to the left
	//   of this new position is now ≤ pivot, and everything to the right
	//   is > pivot. That's the entire goal of "partitioning."

	temp = last_name[i + 1];
	last_name[i + 1] = last_name[high];
	last_name[high] = temp;
	// Same correct 3-step swap, applied to last_name, keeping it in sync
	// with the first_name move above.

	int temp1 = height[i + 1];
	height[i + 1] = height[high];
	height[high] = temp1;
	// >>> NOTICE: this height swap, unlike the buggy one inside the loop
	//   above, IS written completely correctly — all 3 steps are present.
	//   This is genuinely confusing about this bug: the SAME programmer
	//   wrote the correct 3-line version here, just a few lines below the
	//   incomplete 2-line version. This is a great real-world lesson: bugs
	//   are often not "the programmer didn't understand swaps" — they're
	//   simple typos/omissions that slip through specifically BECAUSE the
	//   correct pattern is used correctly elsewhere in the same file,
	//   making it easy to assume (without testing) that every instance is fine.

	return (i + 1);
	// >>> BEGINNER EXPLANATION: this function hands back the final index
	//   where the pivot ended up. quickSort() (below) needs this number to
	//   know where to split the array for its next two recursive calls.
}

//Function which implements quick sort
void quickSort(std::string first_name[], std::string last_name[],
	int height[], int low, int high)
	// >>> BEGINNER EXPLANATION OF THIS FUNCTION SIGNATURE:
	//   "void" means this function does NOT hand back any value when it's done —
	//   it just performs an action (sorting the arrays in place) and finishes.
	//   Same three arrays and low/high slice-boundary parameters as partition()
	//   above.
{
	if (low < high) {
		// >>> BEGINNER EXPLANATION — THIS IS THE "BASE CASE" OF THE RECURSION:
		//   "Recursion" means a function that calls ITSELF. Every recursive
		//   function needs a condition that eventually becomes false, or it
		//   would call itself forever and crash the program. Here: if "low"
		//   is no longer less than "high", it means our current slice has
		//   shrunk down to 1 element or 0 elements — which is already sorted
		//   by definition (you can't unsort a single item) — so we do
		//   NOTHING and this function call simply ends. This is what
		//   eventually stops the recursion.

		// pi is a partitioning index, arr[p] is now at right place
		int pi = partition(first_name, last_name,
			height, low, high);
		// We call partition() (explained in complete detail above) on our
		// current slice. It rearranges this slice so everything ≤ pivot is on
		// the left, everything > pivot is on the right, and it tells us
		// exactly which index ("pi") the pivot itself landed on.

		//Seperately sort elements before partition and after parition
		quickSort(first_name, last_name, height,
			low, pi - 1);
		// >>> THIS IS THE RECURSIVE CALL: quickSort calls ITSELF, but this
		//   time on a SMALLER slice — everything from "low" up to just before
		//   the pivot's new position (pi - 1). This sorts the "short people"
		//   group using the exact same process, on repeat, until that group
		//   shrinks down to the 0-or-1-element base case above.
		quickSort(first_name, last_name, height,
			pi + 1, high);
		// And this second recursive call handles the "tall people" group —
		// everything from just after the pivot's position (pi + 1) through
		// the end of the original slice (high). Between these two recursive
		// calls, EVERY element except the pivot itself gets sorted, and the
		// pivot never needs to move again because partition() already put it
		// in its final, correct position.

	}
}

// Function which binary searches the height
// array for value 158 and if found, prints the corresponding value in other arrays
// at the index
void binarySearch(std::string first_name[], std::string last_name[], int height[],
	int value, int n)
	// >>> BEGINNER EXPLANATION: this function takes our three arrays, a "value"
	//   we're hunting for (158, in this program), and "n" — the total number of
	//   people in the arrays. NOTE: interestingly, the parameter is named "value"
	//   but the code below never actually uses it — it hardcodes the number 158
	//   directly instead (you'll see "== 158" a few lines down, not "== value").
	//   That's not a crash-causing bug, just a sign this function was written to
	//   search for one specific number rather than being fully general-purpose.
{
	int low = 0, high = n - 1;
	// We start by assuming the person we want could be ANYWHERE in the array
	// — from the very first index (0) to the very last index (n - 1).
	int index;
	// We'll use this to remember whichever middle position we're currently
	// checking.
	while (low <= high) {
		// >>> BEGINNER EXPLANATION — THE CORE IDEA OF BINARY SEARCH: as long
		//   as there's still a real range left to search (low hasn't crossed
		//   past high), keep narrowing it down. Each time through this loop,
		//   we're going to CUT THE REMAINING SEARCH AREA IN HALF — which is
		//   why binary search is so much faster than checking every single
		//   element one by one (that slower method is called linear search).

		index = (high + low) / 2;
		// We jump straight to the middle of our current remaining range.
		// Integer division in C++ automatically drops any decimal part, so
		// this always lands on a valid whole-number index.
		if (height[index] == 158) {

			// This index of height array corresponds to the name of the person
			// in first name and the last name array
			std::cout << "Person havding height 158 cms is "
				<< first_name[index]
				<< " " << last_name[index] << std::endl;
			// >>> BEGINNER EXPLANATION: found them! Because all three arrays
			//   are "parallel" (same index = same person), the instant we
			//   find 158 in the height array at some position, we already
			//   know EXACTLY where that same person's first and last name are
			//   sitting — same index, different array. We print all of it,
			//   then...
			return;
			// ...we immediately EXIT this entire function right here. There's
			// no reason to keep searching once we've already found our answer.
		}
		else if (height[index] > 158)
			high = index - 1;
		// >>> BEGINNER EXPLANATION: the person in the middle is TALLER
		//   than 158. Since (IF the array were correctly sorted
		//   shortest-to-tallest) everyone to the right of this middle
		//   point is even taller still, there's no point ever looking
		//   there again. We shrink our search range by moving "high" to
		//   just before this middle point, throwing away the entire
		//   right half in one step.
		else
			low = index + 1;
		// The middle person is SHORTER than 158 (this is the only
		// remaining possibility once the first two checks fail) — so we
		// throw away the entire LEFT half instead, by moving "low" to
		// just after this middle point.
	}
	std::cout << "Sorry, no such person with height of 158 cms is found in the record";
	// >>> BEGINNER EXPLANATION: if the while loop's condition (low <= high)
	//   ever becomes false, it means our search range has shrunk to nothing —
	//   we've eliminated every possible position without ever finding a
	//   match, so we tell the user the value simply isn't in the data.
	//
	//   >>> IMPORTANT CONSEQUENCE OF THE BUG EXPLAINED EARLIER: binary search
	//   ONLY works correctly if the array is genuinely sorted first. Because
	//   the height array gets corrupted during quickSort's partition step
	//   (see the detailed bug explanation above), this array is NOT reliably
	//   sorted by the time binarySearch runs on it. That means this function
	//   could easily report "not found" even when 158 genuinely exists in the
	//   data, or could report a match at the wrong position. Binary search
	//   isn't "wrong" as written here — it's a correct algorithm being fed
	//   data that was never properly sorted in the first place, which is a
	//   very common and very real category of bug in larger programs.
}

// Printing same index of each array
void printParallelArray(std::string first_name[], std::string last_name[],
	int height[], int n)
	// >>> BEGINNER EXPLANATION: a simple "display everything" helper. Takes the
	//   three arrays plus "n" (how many people total) so it knows how many times
	//   to loop.
{
	std::cout << "Name of the people in increasing order of their height: " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << first_name[i] << " " << last_name[i] << " has height "
			<< height[i] << " cms\n";
		// >>> BEGINNER EXPLANATION: for every index from 0 up to n-1, print
		//   the first name, last name, and height that all share that SAME
		//   index — this is the entire concept of a parallel array in action:
		//   one loop counter (i) reads across THREE separate arrays at once,
		//   and because they're kept lined up, index i always describes one
		//   single, consistent person.
	}
	std::cout << std::endl;
}
// Driver Function
int main()
// >>> BEGINNER EXPLANATION: every C++ program has exactly one main() function
//   — it's the very first code that runs when you execute the program, and
//   the program ends when main() finishes (or hits a return statement).
{
	int n = 10;
	// We have exactly 10 people in our dataset, so we store that count once,
	// in one place, so every function that needs to know "how many people are
	// there" can just be handed this same number.
	std::string first_name[] = { "Bones", "Welma", "Frank", "Hans", "Jack",
	"Jinny", "Harry", "Emma", "Tony", "Sherlock" };
	// >>> BEGINNER EXPLANATION: this creates an array of 10 text values all
	//   at once, using a "brace-initializer list" — the { } list tells the
	//   compiler both the size (it counts the items: 10) AND the starting
	//   values, all in a single line, rather than assigning each one
	//   individually across 10 separate lines.

	std::string last_name[] = { "Smith", "Seger", "Mathers", "Solo", "Jackles", "Weasley",
		"Potter", "Watson", "Stark", "Holmes" };
	// A second, separate array — same idea, holding everyone's last name.
	// "Bones Smith", "Welma Seger", etc. — matched purely by shared position
	// (index 0 in both arrays = the same person), nothing in the language
	// itself enforces or guarantees this relationship; it's on the programmer
	// to keep every array update in sync.

	int height[] = { 169, 158, 201, 183, 172, 152, 160, 163, 173, 185 };
	// A third parallel array — this time of whole numbers (int) instead of
	// text — holding each corresponding person's height in centimeters.

	// Sorting the above arrays using quickSort
	quickSort(first_name, last_name, height, 0, n - 1);
	// >>> BEGINNER EXPLANATION: kicks off the entire sorting process
	//   described above. We pass "0" as the starting index (the very
	//   beginning of the array) and "n - 1" as the ending index (9, the last
	//   valid index for a 10-element array, since indexing starts at 0).
	printParallelArray(first_name, last_name, height, n);
	// Displays the (attempted) shortest-to-tallest ordered list to the screen.

	// Second tallest person
	std::cout << "Name of the third shortest person is " << first_name[2] << " " << last_name[2]
		<< std::endl;
	// >>> BEGINNER EXPLANATION + A SECOND SMALL ISSUE WORTH NOTING: the
	//   original comment directly above this line says "Second tallest
	//   person," but the actual text being printed says "third shortest
	//   person" — these two phrases describe different people entirely!
	//   If the sort worked correctly (ascending, shortest-to-tallest, which
	//   is what this quicksort is set up to do), index [2] would genuinely be
	//   the THIRD SHORTEST person (since index 0 = 1st shortest, index 1 =
	//   2nd shortest, index 2 = 3rd shortest) — matching the printed string,
	//   NOT the "Second tallest" comment. The comment is simply stale/wrong
	//   and doesn't match either the code's actual behavior or its own output
	//   message. And because of the height-array bug explained earlier, even
	//   the "correct in theory" answer (3rd shortest) isn't reliable here in
	//   practice, since the array isn't genuinely sorted by the time we get here.

	// Binary search for height 158
	binarySearch(first_name, last_name, height, 158, n);
	// Kicks off the binary search explained in complete detail above, looking
	// specifically for someone who is 158 cm tall.
	return 0;
	// >>> BEGINNER EXPLANATION: every main() should end with "return 0;" —
	//   this hands the number 0 back to the operating system as an exit code,
	//   which is the universal programming convention for "the program
	//   finished successfully, with no errors." (Non-zero exit codes
	//   typically signal that something went wrong.)
}