# Maintainer: Anatol Pomozov
# Contributor: 謝致邦 <Yeking@Red54.com>
# Contributor: Alucryd <alucryd at gmail dot com>

pkgname=android-tools
pkgver=30.0.3
pkgrel=1
_tag=platform-tools-$pkgver
pkgdesc='Android platform tools'
arch=(x86_64)
url='http://tools.android.com/'
license=(Apache MIT)
depends=(pcre2 libusb protobuf brotli)
optdepends=('python: for mkbootimg script'
            'python2: for unpack_bootimg & avbtool scripts')
# it depends on 'vim' because of 'xxd' tool.
makedepends=(git clang gtest ruby cmake ninja go vim)
provides=(fastboot adb)
conflicts=(fastboot adb)
source=(git+https://android.googlesource.com/platform/frameworks/base#tag=$_tag
        git+https://android.googlesource.com/platform/frameworks/native#tag=$_tag
        git+https://android.googlesource.com/platform/system/core#tag=$_tag
        git+https://android.googlesource.com/platform/system/extras#tag=$_tag
        git+https://android.googlesource.com/platform/system/libbase#tag=$_tag
        git+https://android.googlesource.com/platform/system/libziparchive#tag=$_tag
        git+https://android.googlesource.com/platform/system/tools/mkbootimg#tag=$_tag
        git+https://android.googlesource.com/platform/external/selinux#tag=$_tag
        git+https://android.googlesource.com/platform/external/f2fs-tools#tag=$_tag
        git+https://android.googlesource.com/platform/external/e2fsprogs#tag=$_tag
        git+https://android.googlesource.com/platform/external/avb#tag=$_tag
        git+https://android.googlesource.com/platform/external/boringssl#tag=$_tag
        #git+https://boringssl.googlesource.com/boringssl#commit=$_boringssl_commit
        generate_build.rb
# deployagent.jar is a library built from Android sources.
# Building this java library requires a lot of dependencies:
#  java, protobuf-java, dex compiler, Android base libs.
# To avoid the complexity we prebuilt the lib from the Android sources directly
# using following instructions:
#   (See https://wiki.archlinux.org/index.php/Android for context)
# 
#   source build/envsetup.sh
#   lunch full-eng
#   mmm system/core/adb/
#   cp ./target/product/generic/system/framework/deployagent.jar .
        deployagent.jar
# we disable mDNS functionality as it does not compile with the Arch system version of the library
        fix_build_core.patch
        fix_libziparchive.patch
        boringssl-disable-thirdpartydeps.patch
        bash_completion.fastboot)
        # Bash completion file was taken from https://github.com/mbrubeck/android-completion
sha1sums=('SKIP'
          'SKIP'
          'SKIP'
          'SKIP'
          'SKIP'
          'SKIP'
          'SKIP'
          'SKIP'
          'SKIP'
          'SKIP'
          'SKIP'
          'SKIP'
          '8c95ce0bbc39bf1fe37213497af924ad10f195b4'
          'd9dfac30245faa0a96968b96f3acd9ad536f4910'
          '61b1bcf230be39a5f9544e82d43269a20bfb9ef2'
          'ce8314d6b1e05e3f4f7ae7828d225fbb07a2a55c'
          '1c025855a3e7ea351685843a0df45c52a7e674dd'
          '7004dbd0c193668827174880de6f8434de8ceaee')

prepare() {
  cd "$srcdir"/core
  patch -p1 < ../fix_build_core.patch

  cd "$srcdir"/libziparchive
  patch -p1 < ../fix_libziparchive.patch

  cd "$srcdir"/avb
  sed -i 's|/usr/bin/env python$|/usr/bin/env python2|g' avbtool

  cd "$srcdir"/mkbootimg
  sed -i 's|/usr/bin/env python$|/usr/bin/env python2|g' unpack_bootimg.py

  cd "$srcdir"/boringssl
  patch -p1 < ../boringssl-disable-thirdpartydeps.patch
  mkdir -p "$srcdir"/boringssl/src/build
}

build() {
  (cd "$srcdir"/boringssl/src/build && cmake -GNinja ..; ninja crypto/libcrypto.a ssl/libssl.a)

  PLATFORM_TOOLS_VERSION="$pkgver-$pkgrel" ./generate_build.rb > build.ninja
  ninja
}

package() {
  install -m755 -d "$pkgdir"/usr/bin
  install -m755 -t "$pkgdir"/usr/bin fastboot adb mke2fs.android e2fsdroid ext2simg avb/avbtool
  install -Dm 755 mkbootimg/mkbootimg.py "$pkgdir"/usr/bin/mkbootimg
  install -Dm 755 mkbootimg/unpack_bootimg.py "$pkgdir"/usr/bin/unpack_bootimg
  install -Dm 644 bash_completion.fastboot "$pkgdir"/usr/share/bash-completion/completions/fastboot
}
