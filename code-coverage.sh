# Assumes project is located at /app as per dev container

lcov --directory ./build/ --capture --output-file ./code_coverage.info -rc lcov_branch_coverage=1 --exclude '/usr/include/*' --exclude '/app/lib/*' --exclude '/app/src/MainTest.cpp'
genhtml code_coverage.info --branch-coverage --output-directory ./code_coverage_report/
