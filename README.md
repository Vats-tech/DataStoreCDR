# DataStoreCDR
This is a file-based key-value data store that supports the basic CRD (create, read, and delete) operations. This data store is meant to be used as a local storage for one single process on one laptop.

The data store will support the following functional requirements.

1. It can be initialized using an optional file path. If one is not provided,it will reliably create itself in a reasonable location on the laptop.
2. A new key-value pair will be added to the data store using the Create operation. The key always a string - capped at 32chars.
3. If Create is invoked for an existing key, an appropriate error will be shown.
4. A Read operation on a key can be performed by providing the key, and receiving the value in response, as a JSON object.
5. A Delete operation can be performed by providing the key .
6. Appropriate error responses will always be returned to a client if it uses the data store in unexpected ways or breaches any limits.


The data store will also support the following non-functional requirements.

1. The size of the file storing data will never exceed 1GB.
2. A client process is allowed to access the data store using multiple threads, if it desires to The data store is thread-safe.
3. The client will bear as little memory costs as possible to use this data store, while deriving maximum performance with respect to response times for accessing the data store.

Languages: C++
