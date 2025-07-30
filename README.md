<!-- // coding paradigms 
// 1-procedural programming 
// -->writing code line after line
// 2-functional programming
// -->code is written in the form of functions like in stls
// 3-oop 
// -->code is classified into set of object that interact with each other on runtime

// --------------------

// oop entities
// 1-classes
// 2-objects

// and object is an instance from the class
// object is created when we call the constructor of the class

// -----------------

class file{

public:

file(){ //default constructor,if we dont create it ,compiler will do
}

file(string path){ //argument constructor
}

~file(){//destructor -->last function called when the onject is released from the memory
}

private:


}

//object lifecycle :init+running state +de-init
// init is controlled by the constructor
// de-init is controlled by the destructor
// ==========================
// access modifiers
// public 
// private 
// protected

![alt text](image-1.png)

access modifiers controlls what the main function can see from the class file

any function or variable in the public section can be seen by the main file 

any function or variable in the private section can seen only in within the same class and can be used with other functions in the same class and the same with protected modifier

----------------
how to design class

we have requirements --->these requirements contains nouns and verbs -->the nouns are the data-types and classes and the verbs are the variables inside the class --->these requierements go through A-B-C-D-F-G  method then the requirements are converted to the oop


---

main oop features

1-encapsulation
all related functions and variables are encapsulated in the same class

![alt text](image-3.png)


2-abstraction

abstract some function from the caller
if the caller is interested in using read and write functions only for example so these functions will be put inside the public modifier and any other function or variables will be put inside the private modifier and can be passed internally to the functions inside the public modifier

if we have the requirements
open()
read()
write()
file should contain path

so we will have this structure

class file {

public:

read(string path)

write()


private:

open()
string path;

};

so the caller can use only read and write function and the others inside private class can be passed iternally inside public functions

3-inheritance


class file {

public:

read(string path)

write()


private:

open()
string path;

};


class wordfile :public file{

public:


private:


};

so word file will inherit from the file only the functions and variables inside public and protected class

4-polymorphism متعدد الاوجه
behave differently according to the object sent as an argument

class file {

public:

virtual void read(string path){
    cout<<"text file";
}

write()


private:

open()
string path;

};


class wordfile :public file{

public:
void read(string path) override {
    cout<<"word file";
}

private:


};

void print_content(file * f){
    f->read()
}

int main(){

file f1;
wordfile f2;

print_content(&f1);--> text file
print_content(&f2);-->word file


}

  -->

# Object-Oriented Programming (OOP) in C++

## 📌 Coding Paradigms

1. **Procedural Programming**  
   - Code is written line-by-line in a sequential manner.

2. **Functional Programming**  
   - Code is written as a series of functions (e.g., STL functions in C++).
    
3. **Object-Oriented Programming (OOP)**  
   - Code is structured as a collection of **objects** that interact with each other during runtime.

---

## 🔷 OOP Entities

- **Classes**  
- **Objects** → An object is an instance of a class, created using the class constructor.

### Example:

```cpp
class File {
public:
    File() { /* Default constructor */ }

    File(string path) { /* Parameterized constructor */ }

    ~File() { /* Destructor: called when object is destroyed */ }

private:
    // private members
};
```

---

## 🔁 Object Lifecycle

- **Initialization** → controlled by the **constructor**
- **Running State** → the object is in use
- **De-initialization** → controlled by the **destructor**

---

## 🔐 Access Modifiers

| Modifier   | Description                                                |
|------------|------------------------------------------------------------|
| `public`   | Accessible from outside the class                          |
| `private`  | Accessible only from within the same class                 |
| `protected`| Accessible from the class and any class that inherits it  |

```cpp
// Example:
class File {
public:
    void read();
private:
    string path;
protected:
    void open();
};
```

![Access Modifiers](image-1.png)

![alt text](image-9.png)

![alt text](image-10.png)

![alt text](image-11.png)

![alt text](image-12.png)

## what is the difference between encapsulation and data hiding 

![alt text](image-13.png)
![alt text](image-14.png)

data hiding-->using private and public 

abstraction--> using separation between what , how and private,public
---
## Setters and Getters
when the user need to access private data they use te setters and the getters
Don't add setters and getters for private data

![alt text](image-15.png)

![alt text](image-16.png)
---
## 🏗️ Designing a Class from Requirements

1. Start from the **requirements**
2. Identify:
   - **Nouns** → Potential classes or data members
   - **Verbs** → Methods or behaviors
3. Apply the **A-B-C-D-F-G** method (a structured methodology for design)

### Example Requirements:
- `open()`
- `read()`
- `write()`
- File should contain a `path`

→ Leads to the following design:

```cpp
class File {
public:
    void read(string path);
    void write();

private:
    void open();
    string path;
};
```

---
### Complex class example

![alt text](image-7.png)


## 🌟 Main Features of OOP

### ✅ 1. Encapsulation

- Bundles related data (variables) and methods that operate on the data into a single unit (class).
- Helps in data hiding and modularity.

![Encapsulation](image-3.png)

struct also can apply encapsulation concept

![alt text](image-8.png)

---

### 🎭 2. Abstraction

- Hides internal implementation and exposes only necessary parts.
- Achieved using access modifiers.

![alt text](image-18.png)

```cpp
class File {
public:
    void read(string path);
    void write();

private:
    void open();        // Internal helper
    string path;        // Hidden from external access
};
```

> Only `read()` and `write()` are accessible from the main program. `open()` and `path` are internal.

![alt text](image-17.png)

separating what from how 

![alt text](image-19.png)
![alt text](image-20.png)
---

### 🧬 3. Inheritance

- A mechanism for a class (child/derived) to acquire properties and methods of another class (base).

```cpp
class File {
public:
    void read(string path);
    void write();

private:
    void open();
    string path;
};

class WordFile : public File {
    // Inherits public and protected members from File
};
```

> `WordFile` inherits functionality from `File`.

---

### 🌀 4. Polymorphism (متعدد الأوجه)

- Allows functions to behave differently based on the object that calls them.
- Achieved using **virtual functions** and **overriding**.

```cpp
class File {
public:
    virtual void read(string path) {
        cout << "text file";
    }

    void write();

private:
    void open();
    string path;
};

class WordFile : public File {
public:
    void read(string path) override {
        cout << "word file";
    }
};

void print_content(File* f) {
    f->read();
}

int main() {
    File f1;
    WordFile f2;

    print_content(&f1);  // Output: text file
    print_content(&f2);  // Output: word file
}
```

![alt text](image-4.png)

![alt text](image-5.png)
---

## 🧾 Summary

| Concept        | Description                                                            |
|----------------|------------------------------------------------------------------------|
| **Class**      | Blueprint for creating objects                                         |
| **Object**     | Instance of a class                                                    |
| **Encapsulation** | Bundles related data and methods                                    |
| **Abstraction**   | Hides unnecessary details from the user                             |
| **Inheritance**   | Enables reuse and extension of existing code                        |
| **Polymorphism**  | Enables different behaviors with the same interface or base pointer |


![alt text](image-6.png)
---

## 📎 Visuals

- ![Access Modifiers](image-1.png)
- ![Encapsulation Example](image-3.png)

## helpfull slides made by eng:Mostafa Saad

https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbVdWZnpVWU05UTJQeWxUcmM4VDJiQXJfMEJhd3xBQ3Jtc0ttQWk2Q1RQYk5qWmtkRjJvb0hVUmtiTTg4X25DLUZOOXE5V1hpcHFQUzkyVFpHTF9hRW11ckRESm0teVh6M3M0NXVWSVp5dzV6RzVZaGF5UmF6VkcyMXdVX2F1ZWxybnVrVXNjZmV6TUJqMFBkck1lSQ&q=https%3A%2F%2Fdrive.google.com%2Fdrive%2Ffolders%2F1NtU4CkYZlbRiswKV2YXwk3irV4aQ5RmU%3Fusp%3Dsharing&v=cxsYqflY0fM