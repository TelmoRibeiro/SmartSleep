#pragma once

#include "IDisplayManagerTypes.h"

class IDisplayManager {
public:
    /** @brief destroys the display manager
     */
    virtual ~IDisplayManager(void) = default;

    /** @brief starts the display
     */
    virtual void start(void) = 0;

    /** @brief clears the display
     */
    virtual void clear(void) = 0;

    /** @brief plays the text sequence on the display
     *  @param shouldLoop whether to loop the text sequence
     */
    virtual void play(bool shouldLoop) = 0;

    /** @brief updates the display manager -- to be called each iteration of the main loop
     */
    virtual void update(void) = 0;

    /** @brief checks whether the animation sequence has finished playing
     *  @return true if the animation sequence has finished playing, false otherwise
     */
    virtual bool isDone(void) const = 0;

    /** @brief show static text on the display
     *  @param text the static text to display
     *  @param x    the x-coordinate for the text
     *  @param y    the y-coordinate for the text
    */
    virtual void showStaticText(const char* text, int32_t x, int32_t y) = 0;

   /** @brief show scrollable text on the display
    *  @param text            the scrollable text to display
    *  @param scrollDirection the direction of the scroll
    *  @param x               the x-coordinate for the text
    *  @param y               the y-coordinate for the text
    */ 
    virtual void showScrollableText(const char* text, ScrollDirection scrollDirection, int32_t x, int32_t y) = 0;
};