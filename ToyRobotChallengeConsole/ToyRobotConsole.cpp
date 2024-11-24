#include <iostream>

#include "Windows.h"

#include "../ToyRobot/Robot.h"
#include "../ToyRobot/TableTop.h"
#include "../ToyRobot/StreamEntityReporter.h"
#include "../ToyRobot/StreamEntityController.h"

static const int TABLE_WIDTH = 5;
static const int TABLE_HEIGHT = 5;

BOOL WINAPI CtrlHandler(DWORD fdwCtrlType)
{
	if (fdwCtrlType == CTRL_C_EVENT)
	{
		exit(0);
	}

	return FALSE;
}

int main()
{
	if (!SetConsoleCtrlHandler(CtrlHandler, TRUE))
	{
		std::cout << "ERROR: unable to register Control C handler, exiting." << std::endl;
		return 1;
	}

	std::shared_ptr<Robot> robot(new Robot());
	std::shared_ptr<TableTop> table(new TableTop(TABLE_WIDTH, TABLE_HEIGHT));
	std::shared_ptr<std::ostream> output(&std::cout);
	std::shared_ptr<std::istream> input(&std::cin);
	std::shared_ptr<StreamEntityReporter> reporter(new StreamEntityReporter(robot, output));
	std::unique_ptr<StreamEntityController> controller(new StreamEntityController(robot, reporter, table, input));

	while (true)
	{
		std::shared_ptr<Command> cmd = controller->nextCommand();
		if (cmd != nullptr)
			cmd->action();
	}

	return 0;
}
