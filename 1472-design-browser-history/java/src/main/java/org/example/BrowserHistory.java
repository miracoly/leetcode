package org.example;

class BrowserHistory {
    Page current;

    public BrowserHistory(String homepage) {
        current = new Page(homepage);
    }

    public void visit(String url) {
        final var newPage = new Page(url);
        newPage.prev = current;
        current.next = newPage;
        current = newPage;
    }

    public String back(int steps) {
        while (steps > 0 && current.prev != null) {
            current = current.prev;
            steps--;
        }
        return current.url;
    }

    public String forward(int steps) {
        while (steps > 0 && current.next != null) {
            current = current.next;
            steps--;
        }
        return current.url;
    }

    private static class Page {
        String url;
        Page prev;
        Page next;

        Page(String url) {
            this(url, null, null);
        }

        Page(String url, Page prev, Page next) {
            this.url = url;
            this.prev = prev;
            this.next = next;
        }
    }
}
