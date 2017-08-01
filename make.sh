g++ source/ScoreTest.cpp source/Score.cpp source/gameMap.cpp source/mapDriver.cpp source/struct/Color.cpp -o build/scoreTest.out
g++ source/gameMapTest.cpp source/gameMap.cpp source/mapDriver.cpp source/struct/Color.cpp -o build/gameMapTest.out
g++ source/WinCheckerTest.cpp source/winChecker.cpp source/gameMap.cpp source/mapDriver.cpp source/struct/Color.cpp -o build/winCheckerTest.out
g++ source/LevelProcessorTest.cpp source/LevelProcessor.cpp source/gameMap.cpp source/mapDriver.cpp source/struct/Color.cpp -o build/levelProcessorTest.out

g++ main.cpp source/Game.cpp source/Score.cpp source/winChecker.cpp source/LevelProcessor.cpp source/gameMap.cpp source/mapDriver.cpp source/struct/Color.cpp source/struct/Result.cpp source/struct/Counter.cpp -o build/run.out
