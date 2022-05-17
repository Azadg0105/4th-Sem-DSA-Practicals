import random
player = [0,0]
i=0
print("############")
print("GAME BEGINS!")
print("############")
print("position 4,14,28,32 are ladders")
print("position 10,25,38,48 are snakes")
while (player[0]!=50 and player[1]!=50):
    print("player", i+1, "TURN")
    player[i] +=random.randint(1,6)
    if (player[i] ==4 or player[i]==14 or player[i]==28 or player[i]==32):
        print("LUCKY! GOT A LADDER")
        if player[i]==4:
            player[i]==16
        if player[i]==14:
            player[i]==23
        if player[i]==28:
            player[i]==36
    if (player[i]==10 or player[i]==25 or player[i]==38 or player[i]==48):
        print("OOPS! IT'S A SNAKE")
        if player [i]==10:
            player[i]==3
        if player [i]==25:
             player[i]==19
        if player[i]==38:
             player[i]==25
        if player[i]==48:
             player[i]==1
    i=(i+1)%2
if (player[0]==50):
    print("CONGRATULATIONS! PLAYER1 WON")
if (player[1]==50):
    print("CONGRATULATIONS! PLAYER2 WON")
