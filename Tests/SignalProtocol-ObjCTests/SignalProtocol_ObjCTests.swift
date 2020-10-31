import XCTest
@testable import SignalProtocol_ObjC

final class SignalProtocol_ObjCTests: XCTestCase {
    func testExample() {
        // This is an example of a functional test case.
        // Use XCTAssert and related functions to verify your tests produce the correct
        // results.
        XCTAssertEqual(SignalProtocol_ObjC().text, "Hello, World!")
    }

    static var allTests = [
        ("testExample", testExample),
    ]
}
