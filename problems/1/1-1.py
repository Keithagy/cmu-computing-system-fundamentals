"""
Chapter 1: A Tour of Computer Systems

Practice Problem 1.1

Suppose you work as a truck driver, and you have been hired to carry a load of potatoes from Boise, Idaho, to Minneapolis, Minnesota, a total distrance of 2,500 kilometers.
You estimate you can average 100 km/h driving within the speed limits, requiring a total of 25 hours for the trip.

a) You hear on the news that Montana has just abolished its speed limit, which constitutes 1,500 km of the trip.
   Your truck can travel at 150 km/h. What will be your speedup for the trip?

b) You can buy a new turbocharger for your truck. They stock a variety of models, but the faster you want to go, the more it will cost.
   How fast must you travel through Montana to get an overall speedup for your trip of 1.67x?
"""


def solve():
    # Part A
    print("Part A answer:")
    montana_segment_dist_km = 1500
    total_trip_dist_km = 2500

    truck_max_speed_kmh = 150
    average_speed_limit_kmh = 100

    speed_limit_controlled_dist_km = total_trip_dist_km - montana_segment_dist_km

    montana_segment_time_h = montana_segment_dist_km / truck_max_speed_kmh
    speed_limit_controlled_segment_h = (
        speed_limit_controlled_dist_km / average_speed_limit_kmh
    )

    new_time_h = montana_segment_time_h + speed_limit_controlled_segment_h
    old_time_h = 25
    speedup_factor = old_time_h / new_time_h
    print(f"Travel time is now {speedup_factor:.2f}x faster.")

    # Part B
    print("Part B answer:")
    target_overall_speedup_factor = 1.67
    target_new_time = old_time_h / target_overall_speedup_factor
    print(f"Target new time is {target_new_time:.2f} hours.")
    target_montana_segment_time_h = target_new_time - speed_limit_controlled_segment_h
    print(f"target montana segment time is {target_montana_segment_time_h:.2f} hours.")
    target_montana_speed_kmh = montana_segment_dist_km / target_montana_segment_time_h
    print(
        f"For an overall speedup of 1.67x, we must travel through montana at {target_montana_speed_kmh:.2f} km/h."
    )


if __name__ == "__main__":
    solve()
