dice = ['b'] * 55



N = int(input())
for i in range(N):
    dice[1:10] = ['o'] * 9
    dice[10:19] = ['g'] * 9
    dice[19:28] = ['w'] * 9
    dice[28:37] = ['b'] * 9
    dice[37:46] = ['y'] * 9
    dice[46:55] = ['r'] * 9
    T = int(input())
    order_list = input().split()
    for order in order_list:
        if order == "U-":
            dice[19:28] = dice[21],dice[24],dice[27],dice[20],dice[23],dice[26],dice[19],dice[22],dice[25]
            dice[7],dice[8],dice[9],dice[28],dice[31],dice[34],dice[46],dice[47],dice[48],dice[12],dice[15],dice[18]= \
                dice[28], dice[31], dice[34], dice[48], dice[47], dice[46], dice[12], dice[15], dice[18],dice[9],dice[8],dice[7]
        if order == "U+":
            dice[19:28] = dice[25],dice[22],dice[19],dice[26],dice[23],dice[20],dice[27],dice[24],dice[21]
            dice[7], dice[8], dice[9], dice[28], dice[31], dice[34], dice[46], dice[47], dice[48], dice[12], dice[15], dice[18] = \
                (
                dice[18], dice[15], dice[12], dice[7], dice[8], dice[9],dice[34], dice[31], dice[28], dice[46], dice[47], dice[48])
        if order == "D+":
            dice[37:46] = dice[43],dice[40],dice[37],dice[44],dice[41],dice[38],dice[45],dice[42],dice[39]
            dice[1], dice[2], dice[3], dice[30], dice[33], dice[36], dice[52], dice[53], dice[54], dice[10], dice[13],dice[16] = \
                dice[30], dice[33], dice[36], dice[54], dice[53], dice[52], dice[10], dice[13], dice[16], dice[3], dice[2], dice[1]
        if order == "D-":
            dice[37:46] = dice[39], dice[42], dice[45], dice[38], dice[41], dice[44], dice[37], dice[40], dice[43]
            dice[1], dice[2], dice[3], dice[30], dice[33], dice[36], dice[52], dice[53], dice[54], dice[10], dice[13], dice[16] = \
                dice[16], dice[13], dice[10], dice[1], dice[2], dice[3], dice[36], dice[33], dice[30], dice[52], dice[53], dice[54]
            #    dice[16], dice[13], dice[10], dice[3], dice[2], dice[1], dice[36], dice[33], dice[30], dice[54], dice[53], dice[52]
        if order == "F+":
            dice[46:55] = dice[52],dice[49],dice[46],dice[53],dice[50],dice[47],dice[54],dice[51],dice[48]
            dice[16], dice[17], dice[18],dice[25], dice[26],dice[27], dice[34],dice[35],dice[36],dice[43],dice[44],dice[45]=\
            dice[43], dice[44], dice[45], dice[16], dice[17], dice[18], dice[25], dice[26], dice[27], dice[34],dice[35],dice[36]
        if order == "F-":
            dice[46:55] = dice[48], dice[51], dice[54], dice[47], dice[50], dice[53], dice[46], dice[49], dice[52]
            dice[16], dice[17], dice[18], dice[25], dice[26], dice[27], dice[34], dice[35], dice[36], dice[43], dice[44], dice[45] = \
                dice[25], dice[26], dice[27], dice[34], dice[35], dice[36], dice[43], dice[44], dice[45], dice[16], dice[17], dice[18]
        if order == "B+":
            dice[1:10] = dice[7],dice[4],dice[1],dice[8],dice[5],dice[2],dice[9],dice[6],dice[3]
            dice[10], dice[11], dice[12], dice[19], dice[20], dice[21], dice[28],dice[29],dice[30],dice[37],dice[38],dice[39] = \
            dice[19], dice[20], dice[21], dice[28], dice[29], dice[30], dice[37],dice[38],dice[39], dice[10], dice[11],dice[12]
        if order == "B-":

            dice[1:10] = dice[3],dice[6],dice[9],dice[2],dice[5],dice[8],dice[1],dice[4],dice[7]
            dice[10], dice[11], dice[12], dice[19], dice[20], dice[21], dice[28], dice[29], dice[30], dice[37], dice[38], dice[39] = \
                dice[37], dice[38], dice[39], dice[10], dice[11], dice[12], dice[19], dice[20], dice[21], dice[28], dice[29], dice[30]
        if order == "L+":
            dice[10:19] = dice[16],dice[13],dice[10],dice[17],dice[14],dice[11],dice[18],dice[15],dice[12]
            dice[1], dice[4], dice[7], dice[19], dice[22], dice[25], dice[46], dice[49], dice[52], dice[39], dice[42],dice[45] = \
            dice[45],dice[42],dice[39],dice[1], dice[4], dice[7], dice[19], dice[22], dice[25], dice[52],dice[49],dice[46]
        if order == "L-":
            dice[10:19] = dice[12], dice[15], dice[18], dice[11], dice[14], dice[17], dice[10], dice[13], dice[16]
            dice[1], dice[4], dice[7], dice[19],dice[22], dice[25],dice[46],dice[49],dice[52],dice[39],dice[42],dice[45] = \
            dice[19],dice[22],dice[25], dice[46],dice[49],dice[52], dice[45],dice[42],dice[39], dice[7],dice[4],dice[1]
        if order == "R+":
            dice[28:37] = dice[34],dice[31],dice[28],dice[35],dice[32],dice[29],dice[36],dice[33],dice[30]
            dice[3],dice[6],dice[9],dice[21],dice[24],dice[27],dice[48],dice[51],dice[54],dice[37],dice[40],dice[43]= \
                dice[21], dice[24], dice[27], dice[48], dice[51], dice[54],dice[43],dice[40],dice[37],dice[9],dice[6],dice[3]
        if order == "R-":
            dice[28:37] = dice[30], dice[33], dice[36], dice[29], dice[32], dice[35], dice[28], dice[31], dice[34]
            dice[3], dice[6], dice[9], dice[21], dice[24], dice[27], dice[48], dice[51], dice[54], dice[37], dice[40], \
            dice[43] = \
                dice[43], dice[40], dice[37], dice[3], dice[6], dice[9],dice[21], dice[24], dice[27], dice[54], dice[51], dice[48],

    for cnt in (19, 22, 25):
        print("".join(dice[cnt:cnt + 3]))
