#pragma once

#include <string>
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
    virtual void showStaticText(const std::string& text, int32_t x, int32_t y) = 0;

   /** @brief show scrollable text on the display
    *  @param text            the scrollable text to display
    *  @param scrollDirection the direction of the scroll
    *  @param x               the x-coordinate for the text
    *  @param y               the y-coordinate for the text
    */ 
    virtual void showScrollableText(const std::string& text, ScrollDirection scrollDirection, int32_t x, int32_t y) = 0;

    /** @brief sets the font size for the text shown on the display
     *  @param textFontSize the font size for the text shown on the display
     */
    virtual void setTextFontSize(TextFontSize textFontSize) = 0;

    /** @brief gets the font size from the text shown on the display
     *  @return the font size from the text shown on the display
     */
    virtual TextFontSize getTextFontSize(void) const = 0;

    /** @brief sets the colour for the text shown on the display
     *  @param textColour the colour for the text shown on the display
     */
    virtual void setTextColour(uint32_t textColour) = 0;

    /** @brief gets the colour from the text shown on the display
     *  @return the colour from the text shown on the display
     */
    virtual uint32_t getTextColour(void) const = 0;

    /** @brief sets the scroll speed for the text shown on the display
     *  @param scrollSpeedMS the scroll speed in milliseconds for the text shown on the display
     */
    virtual void setScrollSpeedMS(uint32_t scrollSpeedMS) = 0;

    /** @brief gets the scroll speed from the text shown on the display
     *  @return the scroll speed in milliseconds from the text shown on the display
     */
    virtual uint32_t getScrollSpeedMS(void) const = 0;
};