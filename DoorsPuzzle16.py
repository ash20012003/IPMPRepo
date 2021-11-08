door = []
for i in range(101):
  door.append(0)

print(door)

print('\n')
#simulation
for i in range(1,101):
  for j in range(0,101,i):
    if door[j]==0:
      door[j] = 1;
    else:
      door[j] = 0
  

print(door)

openDoor = []
for i in range(1,101):
  if door[i] == 1:
    openDoor.append(i)

print('\n')

print(openDoor)
#All doors that are square numbers are opened