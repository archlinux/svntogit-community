# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Lukas Jirkovsky <l.jirkovsky@gmail.com>

pkgname=krusader
pkgver=2.8.0
pkgrel=1
pkgdesc='Advanced twin panel (commander style) file manager'
arch=(x86_64)
url='https://krusader.org/'
license=(GPL)
depends=(kparts hicolor-icon-theme)
makedepends=(extra-cmake-modules kdoctools)
optdepends=('xz: LZMA and XZ archive support'
            'unzip: ZIP decompression support'
            'zip: ZIP archive support'
            'lhasa: LHA archive support'
            'cpio: cpio archive support'
            'unrar: RAR decompression support'
            'arj: ARJ archive support'
            'unarj: ARJ decompression support'
            'unace: ACE decompression support'
            'p7zip: 7z archive support'
            # additional apps
            'keditbookmarks: Manage Bookmarks functionality'
            'kde-cli-tools: manage file associations, root mode'
            'kompare: file contents comparison'
            'kdiff3: file contents comparison'
            'krename: advanced rename tool'
            'konsole: terminal'
            'ktexteditor: file editing support')
source=(https://download.kde.org/stable/$pkgname/$pkgname-$pkgver.tar.xz)
sha256sums=('8e4cf05a9318b0bc1b0941811b988b2f2bb0c04a0d1e37998212a9190cf2c29a')

build() {
  cmake -B build -S $pkgname-$pkgver \
    -DKDESU_PATH="/usr/lib/kf5/kdesu"
  cmake --build build
}

package() {
  DESTDIR="$pkgdir" cmake --install build
}
