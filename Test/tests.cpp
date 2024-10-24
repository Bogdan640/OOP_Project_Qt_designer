//#include "tests.h"
//#include <cassert>
//#include <iostream>
//using namespace std;
//
//void Tests::testAdd() {
//    // Test add function
//    Repository repo;
//    Service service(repo);
//
//    service.add("M", "blue", 50, 2, "example.com/blue_coat.jpg");
//
//    DynamicVector<Coat> coats = service.get_all();
//    assert(coats.get_size() == 1);
//    assert(coats[0].get_size() == "M");
//    assert(coats[0].get_colour() == "blue");
//    assert(coats[0].get_price() == 50);
//    assert(coats[0].get_quantity() == 2);
//    assert(coats[0].get_photo() == "example.com/blue_coat.jpg");
//}
//
//void Tests::testRemove() {
//    // Test remove function
//    Repository repo;
//    Service service(repo);
//
//    service.add("M", "blue", 50, 2, "example.com/blue_coat.jpg");
//    service.add("L", "red", 60, 1, "example.com/red_coat.jpg");
//
//    service.remove("M", "blue");
//
//    DynamicVector<Coat> coats = service.get_all();
//    assert(coats.get_size() == 1);
//    assert(coats[0].get_size() == "L");
//    assert(coats[0].get_colour() == "red");
//    assert(coats[0].get_price() == 60);
//    assert(coats[0].get_quantity() == 1);
//    assert(coats[0].get_photo() == "example.com/red_coat.jpg");
//}
//
//void Tests::testUpdate() {
//    // Test update function
//    Repository repo;
//    Service service(repo);
//
//    service.add("M", "blue", 50, 2, "example.com/blue_coat.jpg");
//
//    service.update("M", "blue", 60, 3, "example.com/updated_blue_coat.jpg");
//
//    DynamicVector<Coat> coats = service.get_all();
//    assert(coats.get_size() == 1);
//    assert(coats[0].get_price() == 60);
//    assert(coats[0].get_quantity() == 3);
//    assert(coats[0].get_photo() == "example.com/updated_blue_coat.jpg");
//}
//
//void Tests::testInc() {
//    // Test inc function
//    Repository repo;
//    Service service(repo);
//
//    service.add("M", "blue", 50, 2, "example.com/blue_coat.jpg");
//
//    service.inc(0);
//
//    DynamicVector<Coat> coats = service.get_all();
//    assert(coats[0].get_quantity() == 3);
//}
//
//void Tests::testDec() {
//    // Test dec function
//    Repository repo;
//    Service service(repo);
//
//    service.add("M", "blue", 50, 2, "example.com/blue_coat.jpg");
//
//    service.dec(0);
//
//    DynamicVector<Coat> coats = service.get_all();
//    assert(coats[0].get_quantity() == 1);
//}
//
//void Tests::testGetAll() {
//    // Test get_all function
//    Repository repo;
//    Service service(repo);
//
//    service.add("M", "blue", 50, 2, "example.com/blue_coat.jpg");
//
//    DynamicVector<Coat> coats = service.get_all();
//    assert(coats.get_size() == 1);
//}
//
//void Tests::testCheckColourAndSize() {
//    // Test check_colour_and_size function
//    Repository repo;
//    Service service(repo);
//
//    service.add("M", "blue", 50, 2, "example.com/blue_coat.jpg");
//
//    assert(service.check_colour_and_size("M", "blue") == 0);
//    assert(service.check_colour_and_size("L", "red") == 0);
//}
//
//void Tests::testAddGeneratedCoats() {
//    // Test add_generated_coats function
//    Repository repo;
//    Service service(repo);
//
//    service.add_generated_coats();
//
//    DynamicVector<Coat> coats = service.get_all();
//    assert(coats.get_size() == 10);
//}
//
//
//
//
//void Tests::testAddRepo() {
//    Repository repo;
//    Coat coat("M", "blue", 50, 2, "example.com/blue_coat.jpg");
//
//    repo.add_repo(coat);
//
//    assert(repo.get_size() == 1);
//}
//
//void Tests::testRemoveRepo() {
//    Repository repo;
//    Coat coat("M", "blue", 50, 2, "example.com/blue_coat.jpg");
//    repo.add_repo(coat);
//
//    repo.remove_repo(0);
//
//    assert(repo.get_size() == 0);
//}
//
//void Tests::testUpdateRepo() {
//    Repository repo;
//    Coat coat1("M", "blue", 50, 2, "example.com/blue_coat.jpg");
//    repo.add_repo(coat1);
//    Coat coat2("M", "red", 60, 3, "example.com/red_coat.jpg");
//
//    repo.update_repo(coat2, 0);
//    Coat updatedCoat = repo.get_all_repo()[0];
//
//    assert(updatedCoat.get_colour() == "red");
//    assert(updatedCoat.get_price() == 60);
//    assert(updatedCoat.get_quantity() == 3);
//}
//
//void Tests::testRepoInc() {
//    Repository repo;
//    Coat coat("M", "blue", 50, 2, "example.com/blue_coat.jpg");
//    repo.add_repo(coat);
//
//    repo.inc(0);
//
//    Coat updatedCoat = repo.get_all_repo()[0];
//    assert(updatedCoat.get_quantity() == 3);
//}
//
//void Tests::testRepoDec() {
//    Repository repo;
//    Coat coat("M", "blue", 50, 2, "example.com/blue_coat.jpg");
//    repo.add_repo(coat);
//
//    repo.dec(0);
//
//    Coat updatedCoat = repo.get_all_repo()[0];
//    assert(updatedCoat.get_quantity() == 1);
//}
//
//void Tests::testGetSize() {
//    Repository repo;
//    Coat coat1("M", "blue", 50, 2, "example.com/blue_coat.jpg");
//    Coat coat2("L", "red", 60, 3, "example.com/red_coat.jpg");
//    repo.add_repo(coat1);
//    repo.add_repo(coat2);
//
//    assert(repo.get_size() == 2);
//}
//
//void Tests::testGetAllRepo() {
//    Repository repo;
//    Coat coat1("M", "blue", 50, 2, "example.com/blue_coat.jpg");
//    Coat coat2("L", "red", 60, 3, "example.com/red_coat.jpg");
//    repo.add_repo(coat1);
//    repo.add_repo(coat2);
//
//    DynamicVector<Coat> coats = repo.get_all_repo();
//    assert(coats.get_size() == 2);
//    assert(coats[0].get_colour() == "blue");
//    assert(coats[1].get_colour() == "red");
//}
//
//
//void Tests::ctestGetSize() {
//    Coat coat("M", "Blue", 50, 2, "photo.jpg");
//    assert(coat.get_size() == "M");
//}
//
//void Tests::ctestGetColour() {
//    Coat coat("M", "Blue", 50, 2, "photo.jpg");
//    assert(coat.get_colour() == "Blue");
//}
//
//void Tests::ctestGetPrice() {
//    Coat coat("M", "Blue", 50, 2, "photo.jpg");
//    assert(coat.get_price() == 50);
//}
//
//void Tests::ctestGetQuantity() {
//    Coat coat("M", "Blue", 50, 2, "photo.jpg");
//    assert(coat.get_quantity() == 2);
//}
//
//void Tests::ctestInc() {
//    Coat coat("M", "Blue", 50, 2, "photo.jpg");
//    coat.inc();
//    assert(coat.get_quantity() == 3);
//}
//
//void Tests::ctestDec() {
//    Coat coat("M", "Blue", 50, 2, "photo.jpg");
//    coat.dec();
//    assert(coat.get_quantity() == 1);
//}
//
//void Tests::ctestGetPhoto() {
//    Coat coat("M", "Blue", 50, 2, "photo.jpg");
//    assert(coat.get_photo() == "photo.jpg");}
//
//
//
//void Tests::test_dynamic_array()
//{
//    DynamicVector<Coat> da;
//    Repository repo = Repository();
//    Service serv =Service(repo);
//
//    assert(da.get_size() == 0);
//    Coat d = Coat("size", "colour", 1,1, "Photo");
//
//    da.add(d);
//    assert(da.get_size() == 1);
//    assert(da[0].get_size() == "size");
//    assert(da[0].get_colour() == "colour");
//    assert(da[0].get_price() == 1);
//    assert(da[0].get_quantity() == 1);
//    assert(da[0].get_photo() == "Photo");
//
//    da.remove(0);
//    assert(da.get_size() == 0);
//    serv.add_generated_coats();
//
//
//
//    //std::cout << "Test dynamic array" << std::endl;
//
//}
//
//
//
//void Tests::test_remove_2() {
//    // Test remove function
//    DynamicVector<int> vec;
//
//    // Add some elements to the vector
//    for (int i = 0; i < 10; ++i) {
//        vec.add(i);
//    }
//
//    // Remove an element at position 5
//    vec.remove(5);
//
//    // Verify the size after removal
//    assert(vec.get_size() == 9);
//
//    // Verify the elements after removal
//    for (int i = 0; i < 5; ++i) {
//        assert(vec[i] == i);
//    }
//    for (int i = 6; i < 10; ++i) {
//        assert(vec[i - 1] == i);
//    }
//}
//
//void Tests::test_assignment_operator() {
//    // Test assignment operator
//    DynamicVector<int> vec1;
//    DynamicVector<int> vec2;
//
//    // Add some elements to vec1
//    for (int i = 0; i < 10; ++i) {
//        vec1.add(i);
//    }
//
//    // Assign vec1 to vec2
//    vec2 = vec1;
//
//    // Verify the size and elements of vec2
//    assert(vec2.get_size() == vec1.get_size());
//    for (int i = 0; i < 10; ++i) {
//        assert(vec2[i] == vec1[i]);
//    }
//}
//
//
//
//void Tests::test_update2() {
//    // Test update function
//    DynamicVector<int> vec;
//
//    // Add some elements to the vector
//    for (int i = 0; i < 10; ++i) {
//        vec.add(i);
//    }
//
//    // Update an element at position 5
//    vec.update(100, 5);
//
//    // Verify the updated element
//    assert(vec[5] == 100);
//}
//
//
//
//void Tests::test_assignment_operator_service() {
//    // Create two Service objects
//    Repository repo1;
//    Service service1(repo1);
//
//    Repository repo2;
//    Service service2(repo2);
//
//    // Add some coats to service1
//    service1.add("M", "blue", 50, 2, "example.com/blue_coat.jpg");
//    service1.add("L", "red", 60, 1, "example.com/red_coat.jpg");
//
//    // Assign service1 to service2
//    service2 = service1;
//
//    // Check if service2 contains the same coats as service1
//    DynamicVector<Coat> coats1 = service1.get_all();
//    DynamicVector<Coat> coats2 = service2.get_all();
//
//    assert(coats1.get_size() == coats2.get_size());
//
//    for (int i = 0; i < coats1.get_size(); ++i) {
//        assert(coats1[i].get_size() == coats2[i].get_size());
//        assert(coats1[i].get_colour() == coats2[i].get_colour());
//        assert(coats1[i].get_price() == coats2[i].get_price());
//        assert(coats1[i].get_quantity() == coats2[i].get_quantity());
//        assert(coats1[i].get_photo() == coats2[i].get_photo());
//    }
//}
//
//
//
//void Tests::test_default_constructor_service() {
//    // Create a Service object using the default constructor
//    Service service;
//
//    // Verify that the Service object is initialized correctly
//    DynamicVector<Coat> coats = service.get_all();
//
//    // Since the default constructor initializes an empty repository, coats should be empty
//    assert(coats.get_size() == 0);
//}
//
//
//void Tests::test_copy_constructor_1() {
//    // Create a Repository object and add some coats to it
//    Repository originalRepo;
//    originalRepo.add_repo(Coat("M", "blue", 50, 2, "example.com/blue_coat.jpg"));
//    originalRepo.add_repo(Coat("L", "red", 60, 1, "example.com/red_coat.jpg"));
//
//    // Use the copy constructor to create a new Repository object
//    Repository copiedRepo(originalRepo);
//
//    // Verify that the copied repository contains the same data as the original one
//    DynamicVector<Coat> originalCoats = originalRepo.get_all_repo();
//    DynamicVector<Coat> copiedCoats = copiedRepo.get_all_repo();
//
//    // Check if the sizes of the original and copied vectors are the same
//    assert(originalCoats.get_size() == copiedCoats.get_size());
//
//    // Check if each coat in the original repository exists in the copied repository
//    for (int i = 0; i < originalCoats.get_size(); ++i) {
//        // Get the coat at index i from both repositories
//        Coat originalCoat = originalCoats[i];
//        Coat copiedCoat = copiedCoats[i];
//
//        // Verify that the coats have the same attributes
//        assert(originalCoat.get_size() == copiedCoat.get_size());
//        assert(originalCoat.get_colour() == copiedCoat.get_colour());
//        assert(originalCoat.get_price() == copiedCoat.get_price());
//        assert(originalCoat.get_quantity() == copiedCoat.get_quantity());
//        assert(originalCoat.get_photo() == copiedCoat.get_photo());
//    }
//}
//
//
//void Tests::test_copy_assignment_operator_3() {
//    // Create the original repository and add some coats to it
//    Repository originalRepo;
//    originalRepo.add_repo(Coat("M", "blue", 50, 2, "example.com/blue_coat.jpg"));
//    originalRepo.add_repo(Coat("L", "red", 60, 1, "example.com/red_coat.jpg"));
//
//    // Create another repository
//    Repository assignedRepo;
//    assignedRepo=assignedRepo;
//
//    // Use the copy assignment operator to assign the original repository to the new one
//    assignedRepo = originalRepo;
//
//    // Verify that the assigned repository contains the same data as the original one
//    DynamicVector<Coat> originalCoats = originalRepo.get_all_repo();
//    DynamicVector<Coat> assignedCoats = assignedRepo.get_all_repo();
//
//    // Check if the sizes of the original and assigned vectors are the same
//    assert(originalCoats.get_size() == assignedCoats.get_size());
//
//    // Check if each coat in the original repository exists in the assigned repository
//    for (int i = 0; i < originalCoats.get_size(); ++i) {
//        // Get the coat at index i from both repositories
//        Coat originalCoat = originalCoats[i];
//        Coat assignedCoat = assignedCoats[i];
//
//        // Verify that the coats have the same attributes
//        assert(originalCoat.get_size() == assignedCoat.get_size());
//        assert(originalCoat.get_colour() == assignedCoat.get_colour());
//        assert(originalCoat.get_price() == assignedCoat.get_price());
//        assert(originalCoat.get_quantity() == assignedCoat.get_quantity());
//        assert(originalCoat.get_photo() == assignedCoat.get_photo());
//    }
//}
//
//
//void Tests::test_add_with_resize_4() {
//    // Create a DynamicVector of integers
//    DynamicVector<int> vec;
//
//    // Add elements until resizing is triggered
//    for (int i = 0; i < 15; ++i) {
//        vec.add(i);
//        // Verify size after each addition
//        assert(vec.get_size() == i + 1);
//    }
//
//
//
//    // Verify the elements in the vector
//    for (int i = 0; i < 15; ++i) {
//        assert(vec[i] == i);
//    }
//}
//
//
//
//void Tests::runAllTests()  {
//    // Run all test functions
//
//
//    test_dynamic_array();
//
//
//    testAdd();
//    testRemove();
//    testUpdate();
//    testInc();
//    testDec();
//    testGetAll();
//    testCheckColourAndSize();
//    testAddGeneratedCoats();
//
//
//    testAddRepo();
//    testRemoveRepo();
//    testUpdateRepo();
//    testRepoInc();
//    testRepoDec();
//    testGetSize();
//    testGetAllRepo();
//
//
//    ctestGetSize();
//    ctestGetColour();
//    ctestGetPrice();
//    ctestGetQuantity();
//    ctestInc();
//    ctestDec();
//    ctestGetPhoto();
//
//    test_update2();
//    test_remove_2();
//    test_assignment_operator();
//    test_default_constructor_service();
//    test_assignment_operator_service();
//    test_copy_constructor_1();
//    test_copy_assignment_operator_3();
//    test_add_with_resize_4();
////    cout<<"\n\nMUISOOOOR\n\n";
//}
//
//
