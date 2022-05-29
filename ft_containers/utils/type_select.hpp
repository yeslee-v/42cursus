//
// Created by Yeshin Lee on 2022/05/29.
//

#ifndef TYPE_SELECT_HPP
#define TYPE_SELECT_HPP

// for random_access_iterator
// 타입을 선택해준다

namespace ft {
    // const type으로 들어온 것이 아니므로(false) >> T 타입으로 보내줌
    template <typename T, typename ConstType, bool isConst = false>
    struct typeSelector{ typedef T type; };

    // 17번째 줄에서 const type으로 들어왔으므로(true) >> ConstType으로 보내줌
    template <typename T, typename ConstType>
    struct typeSelector<T, ConstType, true> { typedef ConstType type; };
}

#endif
