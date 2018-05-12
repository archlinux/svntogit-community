# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Florian Walch <florian+aur@fwalch.com>
# Contributor: Florian Hahn <flo@fhahn.com>

pkgname=neovim
pkgver=0.2.2
pkgrel=6
pkgdesc='Fork of Vim aiming to improve user experience, plugins, and GUIs'
arch=('x86_64')
url='https://neovim.io'
license=('custom:neovim')
depends=('jemalloc' 'libtermkey' 'libuv' 'msgpack-c' 'unibilium' 'libvterm' 'luajit')
makedepends=('cmake' 'lua51-mpack' 'lua51-lpeg' 'gperf')
optdepends=('python2-neovim: for Python 2 plugin support (see :help python)'
            'python-neovim: for Python 3 plugin support (see :help python)'
            'xclip: for clipboard support (or xsel) (see :help clipboard)'
            'xsel: for clipboard support (or xclip) (see :help clipboard)')
source=(https://github.com/neovim/neovim/archive/v${pkgver}.tar.gz
        3a5721e91ba890718319213154ba6964c9dca4d2.patch)
sha512sums=('5609defe86ac98356f1b9ae9adc6049bb4df920a9a2ae3104f761d52d4dd54cbc84d2596231595dd9b0aa97201fef2121e6c5c86a19267ab6b871dbf4b568209'
            'f3dabd1bbe195a45a10efacfc4bb78007e32b91c32c01e42f8045c6e39d7a5f7e20eea1c4407c313d7ec0bb6d951a0b4e10b402f50d2022a5b4770ec62594a8a')
install=neovim.install

prepare() {
  cd "${srcdir}/neovim-${pkgver}"

  patch -Np1 < "${srcdir}/3a5721e91ba890718319213154ba6964c9dca4d2.patch"
}

build() {
  mkdir -p "${srcdir}/build"
  cd "${srcdir}/build"

  cmake "../neovim-${pkgver}" \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DENABLE_JEMALLOC=ON
  make
}

check() {
  cd "${srcdir}/build"
  ./bin/nvim --version
  ./bin/nvim --headless -u NONE -i NONE -c ':quit'
}

package() {
  cd "${srcdir}/build"
  make DESTDIR="${pkgdir}" install
  cd "${srcdir}/neovim-${pkgver}"
  install -Dm644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
  install -Dm644 runtime/nvim.desktop "${pkgdir}/usr/share/applications/nvim.desktop"
  install -Dm644 runtime/nvim.png "${pkgdir}/usr/share/pixmaps/nvim.png"

  # Make Arch vim packages work
  mkdir -p "${pkgdir}"/usr/share/vim
  echo "set runtimepath+=/usr/share/vim/vimfiles" > "${pkgdir}"/usr/share/nvim/sysinit.vim
}

# vim:set sw=2 sts=2 et:
