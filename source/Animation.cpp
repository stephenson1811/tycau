#include "Animation.h"

/* * * * * * * * * * * * * * * *
@
@
@
* * * * * * * * * * * * * * * */
Animation::Animation(int MaxFrame) {
    m_CurrentFrame    = 0;
    m_MaxFrames       = MaxFrame;

    m_FrameRate       = 100; //Milliseconds
    m_Oscillate       = false;
}

//------------------------------------------------------------------------------
void Animation::play() {
    m_CurrentFrame += 1;

    if(m_Oscillate) {
        if(m_CurrentFrame >= m_MaxFrames - 1) {
                //m_FrameInc = -m_FrameInc;
        }else{
            if(m_CurrentFrame <= 0) {
                //m_FrameInc = -m_FrameInc;
            }
        }
    }else{
        if(m_CurrentFrame >= m_MaxFrames - 1) {
            m_CurrentFrame = 0;
        }
    }
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
int Animation::GetCurrentFrame() {
    return m_CurrentFrame;
}

