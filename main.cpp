#include <iostream>

#include "juce_audio_devices/juce_audio_devices.h"

int main()
{
    juce::ScopedJuceInitialiser_GUI initialiser;

    for (int i = 0; i < 42; ++i)
    {
        std::cout << i << std::endl;

        juce::AudioDeviceManager adm;
        adm.initialise(1, 2, nullptr, true);

        juce::AudioDeviceManager::AudioDeviceSetup setup;
        setup.bufferSize = 512;
        setup.sampleRate = 48000;
        setup.inputChannels = 0b1;
        setup.outputChannels = 0b11;
        setup.inputDeviceName = "BlackHole 2ch";
        setup.outputDeviceName = "MacBook Pro Speakers";

        adm.setAudioDeviceSetup(setup, true);

        setup.sampleRate = 44100;

        adm.setAudioDeviceSetup(setup, true);
    }

    return 0;
}
