package org.example;

import static org.assertj.core.api.Assertions.assertThat;

import org.junit.jupiter.api.Test;

class BrowserHistoryTest {

    @Test
    void testBrowserHistory() {
        BrowserHistory browserHistory = new BrowserHistory("leetcode.com");

        browserHistory.visit("google.com");       // ["leetcode.com", "google.com"]
        browserHistory.visit("facebook.com");     // ["leetcode.com", "google.com", "facebook.com"]
        browserHistory.visit("youtube.com");      // ["leetcode.com", "google.com", "facebook.com", "youtube.com"]

        assertThat(browserHistory.back(1)).isEqualTo("facebook.com"); // move back to "facebook.com"
        assertThat(browserHistory.back(1)).isEqualTo("google.com");   // move back to "google.com"
        assertThat(browserHistory.forward(1)).isEqualTo("facebook.com"); // move forward to "facebook.com"

        browserHistory.visit("linkedin.com");     // ["leetcode.com", "google.com", "facebook.com", "linkedin.com"]

        assertThat(browserHistory.forward(2)).isEqualTo("linkedin.com"); // can't move forward, stays on "linkedin.com"
        assertThat(browserHistory.back(2)).isEqualTo("google.com");   // move back two steps to "google.com"
        assertThat(browserHistory.back(7)).isEqualTo("leetcode.com"); // move back as far as possible to "leetcode.com"
    }

}