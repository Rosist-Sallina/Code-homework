from random import randint, shuffle, choice


ROUND_NUM = 50
PREROUND_NUM = 15
CHEST_NUM = 7

white_list = ['==', '(', ')', '0', '1', 'and', 'or', 'B0',
              'B1', 'B2', 'B3', 'B4', 'B5', 'B6']


def calc(ans, chests, expr):
    B0, B1, B2, B3, B4, B5, B6 = chests
    return ans(eval(expr))


def round():
    chests = [choice((True, False)) for _ in range(CHEST_NUM)]
    print("Seven chests lie here, with mimics or treasure hidden inside.")
    print("But don't worry. Skeleton Merchant knows what to do.")
    print("Be careful, Skeleton Merchant can lie twice!")

    def truth(r): return not not r
    def lie(r): return not r
    lie_num = randint(0, 2)
    lie_status = [truth] * (PREROUND_NUM - lie_num) + [lie] * lie_num
    shuffle(lie_status)

    for i in range(PREROUND_NUM):
        try:
            question = input('Question: ').strip()
            for word in question.split(' '):
                assert word in white_list, f"({word}) No treasure for dirty hacker!"
            result = calc(lie_status[i], chests, question)
            print(f'Answer: {result}!')
        except Exception as e:
            print("Skeleton Merchant fails to understand your words.")
            print(e)
    print('Now open the chests:')
    return chests == list(map(int, input().strip().split(' ')))


if __name__ == '__main__':

    print('Terraria is a land of adventure! A land of mystery!')
    print('Can you get all the treasure without losing your head?')

    for i in range(ROUND_NUM):
        if not round():
            print('A chest suddenly comes alive and BITE YOUR HEAD OFF.')
            exit(0)
        else:
            print('You take all the treasure safe and sound. Head to the next vault!')

    print(f"You've found all the treasure! {flag}")
