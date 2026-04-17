#pragma once

#include "include/IDisplayManager.h"
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

class LEDMatrixDisplayManager : public IDisplayManager {
    static constexpr uint32_t RED_HEX_COLOUR = 0xFFFFFFFFU;

    /** @brief internal state of a LEDMatrixDisplayManager instance
     */
    struct LEDMatrixDisplayManagerContext {
        mutable ArduinoLEDMatrix LEDMatrix{}; /// mutable - boundary between IDisplayManager & Arduino_LED_Matrix
        bool shouldLoop    = false;
        bool isInitialised = false;

        struct TextContext {
            std::string content;
            TextFontSize fontSize           = TextFontSize::Font4x6;
            uint32_t colour                 = RED_HEX_COLOUR;
            ScrollDirection scrollDirection = ScrollDirection::Static;
            int32_t x                       = 0U;
            int32_t y                       = 1U;
            uint32_t scrollSpeedMS          = 100U;
        } text;
    } context;

    /** @brief creates the LEDMatrixDisplayManager
     */
    LEDMatrixDisplayManager(void) = default;

    /** @brief destroys the LEDMatrixDisplayManager
     */
    ~LEDMatrixDisplayManager(void) override = default;

    /** @brief starts the display
     */
    void start(void) override;

public:
    /** @brief copy construction of a LEDMatrixDisplayManager instance is not allowed -- singleton
     */
    LEDMatrixDisplayManager(const LEDMatrixDisplayManager&) = delete;

    /** @brief copy assignment of a LEDMatrixDisplayManager instance is not allowed -- singleton
     */
    LEDMatrixDisplayManager& operator=(const LEDMatrixDisplayManager&) = delete;

    /** @brief gets a reference to a LEDMatrixDisplayManager instance -- singleton
     *  @return the reference to the LEDMatrixDisplayManager instance -- singleton
     */
    static LEDMatrixDisplayManager* getInstance(void);

    /** @brief checks whether the LEDMatrixDisplayManager instance is initialised
     *  @return true if the LEDMatrixDisplayManager instance is initialised, false otherwise
     */
    [[nodiscard]] bool isInitialised(void) const;

    /** @brief initialises the LEDMatrixDisplayManager instance
    */
    void initialise(void);

    /** @brief clears the display
     */
    void clear(void) override;

    /** @brief plays the animation sequence on the display
     *  @param shouldLoop whether to loop the animation sequence
     */
    void play(bool shouldLoop) override;

    /** @brief updates the display manager -- to be called each iteration of the main loop
     */
    void update(void) override;

    /** @brief checks whether the animation sequence has finished playing
     *  @return true if the animation sequence has finished playing, false otherwise
     */
    [[nodiscard]] bool isDone(void) const override;

    /** @brief show static text on the display
     *  @param text the static text to display
     *  @param x    the x-coordinate for the text
     *  @param y    the y-coordinate for the text
    */
    void showStaticText(const std::string& text, int32_t x, int32_t y) override;

   /** @brief show scrollable text on the display
    *  @param text            the scrollable text to display
    *  @param scrollDirection the direction of the scroll
    *  @param x               the x-coordinate for the text
    *  @param y               the y-coordinate for the text
    */ 
    void showScrollableText(const std::string& text, ScrollDirection scrollDirection, int32_t x, int32_t y) override;

    /** @brief sets the font size for the text shown on the display
     *  @param textFontSize the font size for the text shown on the display
     */
    void setTextFontSize(TextFontSize textFontSize) override;

    /** @brief gets the font size from the text shown on the display
     *  @return the font size from the text shown on the display
     */
    [[nodiscard]] TextFontSize getTextFontSize(void) const override;

    /** @brief sets the colour for the text shown on the display
     *  @param textColour the colour for the text shown on the display (default = RED)
     */
    void setTextColour(uint32_t textColour) override;

    /** @brief gets the colour from the text shown on the display
     *  @return the colour from the text shown on the display
     */
    [[nodiscard]] uint32_t getTextColour(void) const override;

    /** @brief sets the scroll speed for the text shown on the display
     *  @param scrollSpeedMS the scroll speed in milliseconds for the text shown on the display
     */
    void setScrollSpeedMS(uint32_t scrollSpeedMS) override;

    /** @brief gets the scroll speed from the text shown on the display
     *  @return the scroll speed in milliseconds from the text shown on the display
     */
    [[nodiscard]] uint32_t getScrollSpeedMS(void) const override;
};