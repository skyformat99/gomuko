g++ source/ScoreTest.cpp source/Config.cpp source/logger.cpp source/Score.cpp source/gameMap.cpp source/mapDriver.cpp source/struct/Color.cpp -o build/scoreTest.out
g++ source/gameMapTest.cpp source/Config.cpp source/logger.cpp source/gameMap.cpp source/mapDriver.cpp source/struct/Color.cpp -o build/gameMapTest.out
g++ source/WinCheckerTest.cpp source/Config.cpp source/logger.cpp source/winChecker.cpp source/gameMap.cpp source/mapDriver.cpp source/struct/Color.cpp -o build/winCheckerTest.out
g++ source/LevelProcessorTest.cpp source/Score.cpp source/Analyzer.cpp source/Config.cpp source/logger.cpp source/LevelProcessor.cpp source/gameMap.cpp source/mapDriver.cpp source/struct/Color.cpp -o build/levelProcessorTest.out
g++ source/AnalyzerTest.cpp source/Analyzer.cpp source/Config.cpp source/Score.cpp source/logger.cpp source/gameMap.cpp source/mapDriver.cpp source/struct/Color.cpp -o build/AnalyzerTest.out

g++ main.cpp source/Config.cpp source/Analyzer.cpp source/logger.cpp source/Game.cpp source/Score.cpp source/winChecker.cpp source/LevelProcessor.cpp source/gameMap.cpp source/mapDriver.cpp source/struct/Color.cpp source/struct/Result.cpp source/struct/Counter.cpp -O3 -o build/run.out
