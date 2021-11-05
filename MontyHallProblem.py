#Monty Hall problem
#Here is the problem taken from the Wiki page.

#Suppose you're on a game show, and you're given the choice of three doors: Behind one door is a car; behind the others, goats. You pick a door, say No. 1, and the host, who knows what's behind the doors, opens another door, say No. 3, which has a goat. He then says to you, "Do you want to pick door No. 2?" Is it to your advantage to switch your choice?

#The assumptions (also taken from Wiki) are as follows:

#Car and goats are placed at random behind the doors.
#Host always picks a door not chosen by contestant.
#Host always reveals a goat and not a car.
#Host always offers a choice to switch from the original door to the other closed door.
#Under the above assumptions, here are the probabilities of winning.

#P(win if contestant chooses to switch) = 2/3

#P(win if contestant does not switch) = 1/3

#You can see the Wiki page for the computation. Let us simulate and find the probability of winning under switch by Monte Carlo.

no = 0   #variable for storing number of event occurence
for i in range(1000):
  car_loc = uniform(3, 1)
  if car_loc == 1:
    goat1_loc = 2; goat2_loc = 3
  elif car_loc == 2:
    goat1_loc = 1; goat2_loc = 3
  else:
    goat1_loc = 1; goat2_loc = 2

  contestant_orig = uniform(3, 1)
  if contestant_orig == goat1_loc:
    host_reveal_loc = goat2_loc; other_closed_door = car_loc
  elif contestant_orig == goat2_loc:
    host_reveal_loc = goat1_loc; other_closed_door = car_loc
  else:
    host_reveal_loc = goat1_loc; other_closed_door = goat2_loc
  if other_closed_door == car_loc:
    no = no + 1

print(no/1000) #probability estimate by Monte Carlo