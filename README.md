# IMC Technical Assessment

Two files corresponding to two different assessments.

## Usage

Highly recommand using docker and mapping the repo to the container.
You can use gcc's official docker image

```bash
docker pull gcc
```
Then mount the repo to the container and run as following instructions.

Both projects are implemented using CMake. 

```bash
cd visitor/build
cd rps_game/build
```
After getting into the root paths of both projects respectively
```bash
cmake ..
```
Then if you want to check the tests, you can go into the /test folder and run
```
./unit_tests
```
Else, if you want to run the project, you can see the executable file under your current path (which is the {$PROJECT_ROOT}/build folder)

## Explaination

### Visitor

Using visitor pattern plus Google test doing some simple unit tests
Will feature type generatlization if I got time and patient

### RPS game

Using factory pattern dynamically creating Rock, Paper and Scissor by using as less memory as possible. (Tho, I don't think it is necessary, but anyway, this is a technical interview, so ...)

Using observer pattern to record the game history.

Using strategy pattern to decouple strategy and data.

Computer will automatically change different strategies according to its wining rate.

In this project, the game is abstrated as player, game information two parts. Game object will never resreve any game history but the current state. Game will reflect every round back to computer player and let it make its own decision. And I think such design is as close as to online client/server module.

Additionally, players have the same interface. But computer player owns strategy interface so that it could leverage different strategies according to the change of the game. And apparently, strategy interface is extendable, implement your own algorithm by inheriting the interface.

## Claim
Some of the design might look overkilled and not necessary, but this is an interview, I hope you can see more.

The two projects did not utilize any other lib or scaffold except STL, CMake and Google Test, all comments are added by hand. And I never used any IDE to build the project even though I could.

Another thing is, I think the n times setting is stupid, which is not realistic. I make the game can keep running and the result will be printed after every single round.

The visitor project could be extendable from the follwoing aspects:
1. the types of visitor (now, only area_visitor, could be something else like color visitor and etc)
2. the types of shape

The RPS project could be extendable from the following aspects:

1. the number of players
2. the number of strategies
3. the types of bets (rock, paper, scissor, plane, rockets and etc...)

## License
[MIT](https://choosealicense.com/licenses/mit/)