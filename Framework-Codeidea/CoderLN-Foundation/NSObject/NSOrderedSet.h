/*
 * NSOrderedSet.h
 *
 * Foundation (c) 2007-2017
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重花时间写作的作者，该模块将系统化学习，后续替换、补充内容或新增文件。
 */
 
#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>
#import <Foundation/NSEnumerator.h>
#import <Foundation/NSArray.h>

@class NSArray, NSIndexSet, NSSet<ObjectType>, NSString;

/****************       Immutable Ordered Set   ****************/

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_7, 5_0)
@interface NSOrderedSet<__covariant ObjectType> : NSObject <NSCopying, NSMutableCopying, NSSecureCoding, NSFastEnumeration>

@property (readonly) NSUInteger count;
- (ObjectType)objectAtIndex:(NSUInteger)idx;
- (NSUInteger)indexOfObject:(ObjectType)object;
- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithObjects:(const ObjectType _Nonnull [_Nullable])objects count:(NSUInteger)cnt NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end

@interface NSOrderedSet<ObjectType> (NSExtendedOrderedSet)

- (void)getObjects:(ObjectType _Nonnull __unsafe_unretained [_Nullable])objects range:(NSRange)range NS_SWIFT_UNAVAILABLE("Use 'array' instead");
- (NSArray<ObjectType> *)objectsAtIndexes:(NSIndexSet *)indexes;
@property (nullable, nonatomic, readonly) ObjectType firstObject;
@property (nullable, nonatomic, readonly) ObjectType lastObject;

- (BOOL)isEqualToOrderedSet:(NSOrderedSet<ObjectType> *)other;

- (BOOL)containsObject:(ObjectType)object;
- (BOOL)intersectsOrderedSet:(NSOrderedSet<ObjectType> *)other;
- (BOOL)intersectsSet:(NSSet<ObjectType> *)set;

- (BOOL)isSubsetOfOrderedSet:(NSOrderedSet<ObjectType> *)other;
- (BOOL)isSubsetOfSet:(NSSet<ObjectType> *)set;

- (ObjectType)objectAtIndexedSubscript:(NSUInteger)idx API_AVAILABLE(macos(10.8), ios(6.0), watchos(2.0), tvos(9.0));

- (NSEnumerator<ObjectType> *)objectEnumerator;
- (NSEnumerator<ObjectType> *)reverseObjectEnumerator;

@property (readonly, copy) NSOrderedSet<ObjectType> *reversedOrderedSet;

// These two methods return a facade object for the receiving ordered set,
// which acts like an immutable array or set (respectively).  Note that
// while you cannot mutate the ordered set through these facades, mutations
// to the original ordered set will "show through" the facade and it will
// appear to change spontaneously, since a copy of the ordered set is not
// being made.
@property (readonly, strong) NSArray<ObjectType> *array;
@property (readonly, strong) NSSet<ObjectType> *set;

- (void)enumerateObjectsUsingBlock:(void (NS_NOESCAPE ^)(ObjectType obj, NSUInteger idx, BOOL *stop))block;
- (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (NS_NOESCAPE ^)(ObjectType obj, NSUInteger idx, BOOL *stop))block;
- (void)enumerateObjectsAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts usingBlock:(void (NS_NOESCAPE ^)(ObjectType obj, NSUInteger idx, BOOL *stop))block;

- (NSUInteger)indexOfObjectPassingTest:(BOOL (NS_NOESCAPE ^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;
- (NSUInteger)indexOfObjectWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (NS_NOESCAPE ^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;
- (NSUInteger)indexOfObjectAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts passingTest:(BOOL (NS_NOESCAPE ^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;

- (NSIndexSet *)indexesOfObjectsPassingTest:(BOOL (NS_NOESCAPE ^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;
- (NSIndexSet *)indexesOfObjectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (NS_NOESCAPE ^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;
- (NSIndexSet *)indexesOfObjectsAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts passingTest:(BOOL (NS_NOESCAPE ^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;

- (NSUInteger)indexOfObject:(ObjectType)object inSortedRange:(NSRange)range options:(NSBinarySearchingOptions)opts usingComparator:(NSComparator NS_NOESCAPE)cmp; // binary search

- (NSArray<ObjectType> *)sortedArrayUsingComparator:(NSComparator NS_NOESCAPE)cmptr;
- (NSArray<ObjectType> *)sortedArrayWithOptions:(NSSortOptions)opts usingComparator:(NSComparator NS_NOESCAPE)cmptr;

@property (readonly, copy) NSString *description;
- (NSString *)descriptionWithLocale:(nullable id)locale;
- (NSString *)descriptionWithLocale:(nullable id)locale indent:(NSUInteger)level;

@end

@interface NSOrderedSet<ObjectType> (NSOrderedSetCreation)

+ (instancetype)orderedSet;
+ (instancetype)orderedSetWithObject:(ObjectType)object;
+ (instancetype)orderedSetWithObjects:(const ObjectType _Nonnull [_Nonnull])objects count:(NSUInteger)cnt;
+ (instancetype)orderedSetWithObjects:(ObjectType)firstObj, ... NS_REQUIRES_NIL_TERMINATION;
+ (instancetype)orderedSetWithOrderedSet:(NSOrderedSet<ObjectType> *)set;
+ (instancetype)orderedSetWithOrderedSet:(NSOrderedSet<ObjectType> *)set range:(NSRange)range copyItems:(BOOL)flag;
+ (instancetype)orderedSetWithArray:(NSArray<ObjectType> *)array;
+ (instancetype)orderedSetWithArray:(NSArray<ObjectType> *)array range:(NSRange)range copyItems:(BOOL)flag;
+ (instancetype)orderedSetWithSet:(NSSet<ObjectType> *)set;
+ (instancetype)orderedSetWithSet:(NSSet<ObjectType> *)set copyItems:(BOOL)flag;

- (instancetype)initWithObject:(ObjectType)object;
- (instancetype)initWithObjects:(ObjectType)firstObj, ... NS_REQUIRES_NIL_TERMINATION;
- (instancetype)initWithOrderedSet:(NSOrderedSet<ObjectType> *)set;
- (instancetype)initWithOrderedSet:(NSOrderedSet<ObjectType> *)set copyItems:(BOOL)flag;
- (instancetype)initWithOrderedSet:(NSOrderedSet<ObjectType> *)set range:(NSRange)range copyItems:(BOOL)flag;
- (instancetype)initWithArray:(NSArray<ObjectType> *)array;
- (instancetype)initWithArray:(NSArray<ObjectType> *)set copyItems:(BOOL)flag;
- (instancetype)initWithArray:(NSArray<ObjectType> *)set range:(NSRange)range copyItems:(BOOL)flag;
- (instancetype)initWithSet:(NSSet<ObjectType> *)set;
- (instancetype)initWithSet:(NSSet<ObjectType> *)set copyItems:(BOOL)flag;

@end

/****************       Mutable Ordered Set     ****************/

NS_CLASS_AVAILABLE(10_7, 5_0)
@interface NSMutableOrderedSet<ObjectType> : NSOrderedSet<ObjectType>

- (void)insertObject:(ObjectType)object atIndex:(NSUInteger)idx;
- (void)removeObjectAtIndex:(NSUInteger)idx;
- (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(ObjectType)object;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithCapacity:(NSUInteger)numItems NS_DESIGNATED_INITIALIZER;

@end

@interface NSMutableOrderedSet<ObjectType> (NSExtendedMutableOrderedSet)

- (void)addObject:(ObjectType)object;
- (void)addObjects:(const ObjectType _Nonnull [_Nullable])objects count:(NSUInteger)count;
- (void)addObjectsFromArray:(NSArray<ObjectType> *)array;

- (void)exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2;
- (void)moveObjectsAtIndexes:(NSIndexSet *)indexes toIndex:(NSUInteger)idx;

- (void)insertObjects:(NSArray<ObjectType> *)objects atIndexes:(NSIndexSet *)indexes;

- (void)setObject:(ObjectType)obj atIndex:(NSUInteger)idx;
- (void)setObject:(ObjectType)obj atIndexedSubscript:(NSUInteger)idx API_AVAILABLE(macos(10.8), ios(6.0), watchos(2.0), tvos(9.0));

- (void)replaceObjectsInRange:(NSRange)range withObjects:(const ObjectType _Nonnull [_Nullable])objects count:(NSUInteger)count;
- (void)replaceObjectsAtIndexes:(NSIndexSet *)indexes withObjects:(NSArray<ObjectType> *)objects;

- (void)removeObjectsInRange:(NSRange)range;
- (void)removeObjectsAtIndexes:(NSIndexSet *)indexes;
- (void)removeAllObjects;

- (void)removeObject:(ObjectType)object;
- (void)removeObjectsInArray:(NSArray<ObjectType> *)array;

- (void)intersectOrderedSet:(NSOrderedSet<ObjectType> *)other;
- (void)minusOrderedSet:(NSOrderedSet<ObjectType> *)other;
- (void)unionOrderedSet:(NSOrderedSet<ObjectType> *)other;

- (void)intersectSet:(NSSet<ObjectType> *)other;
- (void)minusSet:(NSSet<ObjectType> *)other;
- (void)unionSet:(NSSet<ObjectType> *)other;

#if NS_BLOCKS_AVAILABLE
- (void)sortUsingComparator:(NSComparator NS_NOESCAPE)cmptr;
- (void)sortWithOptions:(NSSortOptions)opts usingComparator:(NSComparator NS_NOESCAPE)cmptr;
- (void)sortRange:(NSRange)range options:(NSSortOptions)opts usingComparator:(NSComparator NS_NOESCAPE)cmptr;
#endif

@end

@interface NSMutableOrderedSet<ObjectType> (NSMutableOrderedSetCreation)

+ (instancetype)orderedSetWithCapacity:(NSUInteger)numItems;

@end
NS_ASSUME_NONNULL_END

