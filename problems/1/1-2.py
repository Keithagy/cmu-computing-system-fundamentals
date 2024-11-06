"""
Chapter 1: A Tour of Computer Systems

Practice Problem 1.2

The marketing department at your company has promised your customers that the next software release will show a 2x performance improvement.
You have been assigned the task of delivering on that promise.
You have determined that only 80% of the system can be improved. 
How much (i.e., what value of k) would you need to improve this part to meet the overall performance target?
"""


def solve():
    target_perf_improvement_factor = 2
    part_of_system_improvable = 0.8
    target_improvement_factor = 1 / (
        ((1 / target_perf_improvement_factor) - (1 - part_of_system_improvable))
        / (part_of_system_improvable)
    )  # by Amdahl's Law
    print(
        f"You would need to improve 80% of the system by {target_improvement_factor:.2f}x to meet the 2x performance improvement target."
    )


if __name__ == "__main__":
    solve()
