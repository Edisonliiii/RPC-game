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

## License
[MIT](https://choosealicense.com/licenses/mit/)