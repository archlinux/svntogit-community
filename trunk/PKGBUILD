# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Jan "heftig" Steffens <jan.steffens@gmail.com>
# Contributor: Eduardo Romero <eduardo@archlinux.org>
# Contributor: Giovanni Scafora <giovanni@archlinux.org>

pkgname=wine-staging
pkgver=8.4
pkgrel=1

#_winever=${pkgver%.*}
#_winever=$pkgver
_pkgbasever=${pkgver/rc/-rc}
_winever=$_pkgbasever

source=(https://dl.winehq.org/wine/source/8.x/wine-$_winever.tar.xz{,.sign}
        "https://github.com/wine-staging/wine-staging/archive/v$_pkgbasever/wine-staging-v$_pkgbasever.tar.gz"
        30-win32-aliases.conf
        wine-binfmt.conf)
sha512sums=('8de144a65c0a3a2984fabc1294b647b8581da5fa8bd28a9ff756ab59256ee2b453d898453fc902bbc372a4e017a8e29b1eeef917f137ec1134ac08b671eccc7d'
            'SKIP'
            '96a6a870020e59f8437c65604536fec4b80d7d9e5a937e5d0a6cb0b2b4e544e6153fa0cdf2a8fd2c32d090001334e68124c2855c6a2a1454fdcdb6ea23d75fd7'
            '6e54ece7ec7022b3c9d94ad64bdf1017338da16c618966e8baf398e6f18f80f7b0576edf1d1da47ed77b96d577e4cbb2bb0156b0b11c183a0accf22654b0a2bb'
            'bdde7ae015d8a98ba55e84b86dc05aca1d4f8de85be7e4bd6187054bfe4ac83b5a20538945b63fb073caab78022141e9545685e4e3698c97ff173cf30859e285')
validpgpkeys=(5AC1A08B03BD7A313E0A955AF5E6E9EEB9461DD7
              DA23579A74D4AD9AF9D3F945CEFAC8EAAF17519D)

pkgdesc="A compatibility layer for running Windows programs - Staging branch"
url="https://www.wine-staging.com"
arch=(x86_64)
options=(staticlibs !lto)
license=(LGPL)

depends=(
  attr             lib32-attr
  fontconfig       lib32-fontconfig
  libxcursor       lib32-libxcursor
  libxrandr        lib32-libxrandr
  libxi            lib32-libxi
  gettext          lib32-gettext
  freetype2        lib32-freetype2
  gcc-libs         lib32-gcc-libs
  libpcap          lib32-libpcap
  desktop-file-utils
)

makedepends=(autoconf bison perl flex mingw-w64-gcc
  giflib                lib32-giflib
  gnutls                lib32-gnutls
  libxinerama           lib32-libxinerama
  libxcomposite         lib32-libxcomposite
  libxxf86vm            lib32-libxxf86vm
  v4l-utils             lib32-v4l-utils
  alsa-lib              lib32-alsa-lib
  libxcomposite         lib32-libxcomposite
  mesa                  lib32-mesa
  mesa-libgl            lib32-mesa-libgl
  opencl-icd-loader     lib32-opencl-icd-loader
  libpulse              lib32-libpulse
  libva                 lib32-libva
  gtk3                  lib32-gtk3
  gst-plugins-base-libs lib32-gst-plugins-base-libs
  vulkan-icd-loader     lib32-vulkan-icd-loader
  sdl2                  lib32-sdl2
  libcups               lib32-libcups
  sane
  libgphoto2
  ffmpeg
  samba
  opencl-headers
)

optdepends=(
  giflib                lib32-giflib
  gnutls                lib32-gnutls
  v4l-utils             lib32-v4l-utils
  libpulse              lib32-libpulse
  alsa-plugins          lib32-alsa-plugins
  alsa-lib              lib32-alsa-lib
  libxcomposite         lib32-libxcomposite
  libxinerama           lib32-libxinerama
  opencl-icd-loader     lib32-opencl-icd-loader
  libva                 lib32-libva
  gtk3                  lib32-gtk3
  gst-plugins-base-libs lib32-gst-plugins-base-libs
  vulkan-icd-loader     lib32-vulkan-icd-loader
  sdl2                  lib32-sdl2
  sane
  libgphoto2
  ffmpeg
  cups
  samba           dosbox
)

provides=("wine=$pkgver" "wine-wow64=$pkgver")
conflicts=('wine' 'wine-wow64')
install=wine.install

prepare() {
  # Allow ccache to work
  mv wine-$_winever $pkgname

  # Get rid of old build dirs
  rm -rf $pkgname-{32,64}-build
  mkdir $pkgname-{32,64}-build

  # apply wine-staging patchset
  cd $pkgname
  ../wine-staging-$_pkgbasever/staging/patchinstall.py --all

  # Doesn't compile without remove these flags as of 4.10
  export CFLAGS="${CFLAGS/-fno-plt/}"
  export LDFLAGS="${LDFLAGS/,-z,now/}"
}

build() {
  cd "$srcdir"

  msg2 "Building Wine-64..."

  cd "$srcdir/$pkgname-64-build"
  ../$pkgname/configure \
    --prefix=/usr \
    --libdir=/usr/lib \
    --with-x \
    --with-gstreamer \
    --enable-win64 \
    --with-xattr

  make

  msg2 "Building Wine-32..."

  export PKG_CONFIG_PATH="/usr/lib32/pkgconfig"
  cd "$srcdir/$pkgname-32-build"
  ../$pkgname/configure \
    --prefix=/usr \
    --with-x \
    --with-gstreamer \
    --with-xattr \
    --libdir=/usr/lib32 \
    --with-wine64="$srcdir/$pkgname-64-build"

  make
}

package() {
  msg2 "Packaging Wine-32..."
  cd "$srcdir/$pkgname-32-build"

  make prefix="$pkgdir/usr" \
    libdir="$pkgdir/usr/lib32" \
    dlldir="$pkgdir/usr/lib32/wine" install

  msg2 "Packaging Wine-64..."
  cd "$srcdir/$pkgname-64-build"
  make prefix="$pkgdir/usr" \
    libdir="$pkgdir/usr/lib" \
    dlldir="$pkgdir/usr/lib/wine" install

  # Font aliasing settings for Win32 applications
  install -d "$pkgdir"/usr/share/fontconfig/conf.{avail,default}
  install -m644 "$srcdir/30-win32-aliases.conf" "$pkgdir/usr/share/fontconfig/conf.avail"
  ln -s ../conf.avail/30-win32-aliases.conf "$pkgdir/usr/share/fontconfig/conf.default/30-win32-aliases.conf"
  install -Dm 644 "$srcdir/wine-binfmt.conf" "$pkgdir/usr/lib/binfmt.d/wine.conf"

  i686-w64-mingw32-strip --strip-unneeded "$pkgdir"/usr/lib32/wine/i386-windows/*.dll
  x86_64-w64-mingw32-strip --strip-unneeded "$pkgdir"/usr/lib/wine/x86_64-windows/*.dll
}

# vim:set ts=8 sts=2 sw=2 et:
