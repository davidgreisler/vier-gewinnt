#include "Replay.hpp"

#include <QAction>
#include <QEvent>
#include <QWidget>
#include <QMenu>
#include <QIcon>

namespace GUI
{
namespace Actions
{

/**
 * Creates a new replay action container.
 *
 * @param parentWindow Parent window, used for dialogs.
 * @param parent Parent object.
 */
Replay::Replay(QWidget* parentWindow, QObject* parent) :
	QObject(parent), parentWindow(parentWindow)
{
	this->createActions();
	this->createMenu();
	this->retranslateUI();
}

/**
 * Frees all used resources.
 */
Replay::~Replay()
{

}

/**
 * Returns the load replay action.
 *
 * @return Action for loading a replay.
 */
QAction* Replay::getLoadReplayAction() const
{
	return this->loadReplayAction;
}

/**
 * Returns the save replay action.
 *
 * @return Action for saving the replay of the current game.
 */
QAction* Replay::getSaveReplayAction() const
{
	return this->saveReplayAction;
}

/**
 * Returns the next move action.
 *
 * @return Action for stepping to the next move.
 */
QAction* Replay::getNextMoveAction() const
{
	return this->nextMoveAction;
}

/**
 * Returns the previous move action.
 *
 * @return Action for stepping to the previous move.
 */
QAction* Replay::getPreviousMoveAction() const
{
	return this->previousMoveAction;
}

/**
 * Returns the jump to start action.
 *
 * @return Action for jumping back to start of the replay.
 */
QAction* Replay::getJumpToStartAction() const
{
	return this->jumpToStartAction;
}

/**
 * Returns the jump to end action.
 *
 * @return Action for jumping to the end of the replay.
 */
QAction* Replay::getJumpToEndAction() const
{
	return this->jumpToEndAction;
}

/**
 * Returns the replay menu.
 *
 * The replay menu contains all replay actions.
 *
 * @return The replay menu.
 */
QMenu* Replay::getMenu() const
{
	return this->menu.data();
}

/**
 * Load a replay.
 */
void Replay::loadReplay()
{

}

/**
 * Save a replay of the current game.
 */
void Replay::saveReplay()
{

}

/**
 * Step to the next move.
 */
void Replay::nextMove()
{

}

/**
 * Step to the previous move.
 */
void Replay::previousMove()
{

}

/**
 * Jump to the start of the replay.
 */
void Replay::jumpToStart()
{

}

/**
 * Jump to the end of the replay.
 */
void Replay::jumpToEnd()
{

}

/**
 * Create all actions and connect them.
 */
void Replay::createActions()
{
	QIcon loadReplayIcon;
	loadReplayIcon.addFile(":/icons/16x16/film.png", QSize(16, 16));
	loadReplayIcon.addFile(":/icons/32x32/film.png", QSize(32, 32));
	this->loadReplayAction = new QAction(loadReplayIcon, "", this);

	QIcon saveReplayIcon;
	saveReplayIcon.addFile(":/icons/16x16/film_save.png", QSize(16, 16));
	saveReplayIcon.addFile(":/icons/32x32/film_save.png", QSize(32, 32));
	this->saveReplayAction = new QAction(saveReplayIcon, "", this);

	QIcon nextMoveIcon;
	nextMoveIcon.addFile(":/icons/16x16/control_play_blue.png", QSize(16, 16));
	nextMoveIcon.addFile(":/icons/32x32/control_play_blue.png", QSize(32, 32));
	this->nextMoveAction = new QAction(nextMoveIcon, "", this);

	QIcon previousMoveIcon;
	previousMoveIcon.addFile(":/icons/16x16/control_play_blue_mirror.png", QSize(16, 16));
	previousMoveIcon.addFile(":/icons/32x32/control_play_blue_mirror.png", QSize(32, 32));
	this->previousMoveAction = new QAction(previousMoveIcon, "", this);

	QIcon jumpToStartIcon;
	jumpToStartIcon.addFile(":/icons/16x16/control_start_blue.png", QSize(16, 16));
	jumpToStartIcon.addFile(":/icons/32x32/control_start_blue.png", QSize(32, 32));
	this->jumpToStartAction = new QAction(jumpToStartIcon, "", this);

	QIcon jumpToEndIcon;
	jumpToEndIcon.addFile(":/icons/16x16/control_end_blue.png", QSize(16, 16));
	jumpToEndIcon.addFile(":/icons/32x32/control_end_blue.png", QSize(32, 32));
	this->jumpToEndAction = new QAction(jumpToEndIcon, "", this);

	this->connect(this->loadReplayAction, &QAction::triggered, this, &Replay::loadReplay);
	this->connect(this->saveReplayAction, &QAction::triggered, this, &Replay::saveReplay);
	this->connect(this->nextMoveAction, &QAction::triggered, this, &Replay::nextMove);
	this->connect(this->previousMoveAction, &QAction::triggered, this, &Replay::previousMove);
	this->connect(this->jumpToStartAction, &QAction::triggered, this, &Replay::jumpToStart);
	this->connect(this->jumpToEndAction, &QAction::triggered, this, &Replay::jumpToEnd);
}

/**
 * Creates the replay menu.
 */
void Replay::createMenu()
{
	this->menu.reset(new QMenu(0));
	this->menu->addAction(this->loadReplayAction);
	this->menu->addAction(this->saveReplayAction);
	this->menu->addSeparator();
	this->menu->addAction(this->nextMoveAction);
	this->menu->addAction(this->previousMoveAction);
	this->menu->addAction(this->jumpToStartAction);
	this->menu->addAction(this->jumpToEndAction);
}

/**
 * Retranslates all strings.
 */
void Replay::retranslateUI()
{
	this->loadReplayAction->setText(tr("&Load replay ..."));
	this->loadReplayAction->setStatusTip(tr("Load a replay."));

	this->saveReplayAction->setText(tr("&Save replay ..."));
	this->saveReplayAction->setStatusTip(tr("Save a replay of the current game."));

	this->nextMoveAction->setText(tr("&Next move"));
	this->nextMoveAction->setStatusTip(tr("Step to the next move."));

	this->previousMoveAction->setText(tr("&Previous move"));
	this->previousMoveAction->setStatusTip(tr("Step to the previous move."));

	this->jumpToStartAction->setText(tr("&Jump to start"));
	this->jumpToStartAction->setStatusTip(tr("Jump to the start of the replay."));

	this->jumpToEndAction->setText(tr("&Jump to end"));
	this->jumpToEndAction->setStatusTip(tr("Jump to the end of the replay."));

	this->menu->setTitle(tr("&Replay"));
}

/**
 * Retranslates strings when the application's language has been changed.
 *
 * @param event Change event.
 */
bool Replay::event(QEvent* event)
{
	if (event->type() == QEvent::LanguageChange)
	{
		this->retranslateUI();
	}

	return QObject::event(event);
}

}
}