<body>
    <h1>Computer Systems II</h1>
    <h2>Program 1</h2>
    <h3>Spring 2024</h3>
    <h4>System Calls vs. Function Calls</h4>
    <p>
        <strong>Question:</strong> Are system calls more expensive than function calls? Write a simple test program to compare the "cost" of a simple function call to a simple system call. 
    </p>
    <p>
        <strong>Note:</strong> Be careful to prevent the optimizing compiler from "optimizing out" your function calls. Do not compile with optimization on.
    </p>
    <p>
        Explain the difference (if any) between the time required by simple function call and simple system call by discussing what work each call must do. Be specific. You should use system calls such as <code>gethrtime()</code> or <code>gettimeofday()</code> for time measurements. Design your code such that the measurement overhead is negligible. Also, be aware that timer values in some systems have limited resolution (e.g., millisecond).
    </p>
    <p>Compare "cost" for the following:</p>
    <ul>
        <li><code>getuid()</code> system call</li>
        <li><code>getppid()</code> system call</li>
        <li><code>getcwd()</code> system call</li>
        <li><code>write()</code> system call</li>
        <li><code>read()</code> system call</li>
        <li>function <code>foo()</code></li>
    </ul>
    <p>Example function <code>foo</code>:</p>
    <pre><code>int foo() {
    return(10);
}</code></pre>
</body>
</html>
