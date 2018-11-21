# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Florian Walch <florian+aur@fwalch.com>
# Contributor: Florian Hahn <flo@fhahn.com>

pkgname=neovim
pkgver=0.3.1
pkgrel=2
pkgdesc='Fork of Vim aiming to improve user experience, plugins, and GUIs'
arch=('x86_64')
url='https://neovim.io'
license=('custom:neovim')
depends=('jemalloc' 'libtermkey' 'libuv' 'msgpack-c' 'unibilium' 'libvterm' 'luajit')
makedepends=('cmake' 'ninja' 'lua51-mpack' 'lua51-lpeg' 'gperf')
optdepends=('python2-neovim: for Python 2 plugin support (see :help python)'
            'python-neovim: for Python 3 plugin support (see :help python)'
            'xclip: for clipboard support (or xsel) (see :help clipboard)'
            'xsel: for clipboard support (or xclip) (see :help clipboard)')
source=(https://github.com/neovim/neovim/archive/v${pkgver}.tar.gz
        https://github.com/neovim/neovim/pull/8859/commits/4a46ab8de9a9a9aee36546740c45b9e65a9e7dc9.patch)
sha512sums=('42c541608509dc0335203ee1c008045f0eaeebce8e18dffc554ab22a029da700bba9b8c721bd9d68337ddb4a56f8cf034fad2a3eb88d36baf8295e6648fce506'
            '2b6bec34006995ed4b682b3fdef260935a6cc0857b41304571adb36d911f2597624c298d4375aa9ac9115733918f61d51c1cbd0de5799680ffff36b0d6219ded')
install=neovim.install

prepare() {
  cd "${srcdir}/neovim-${pkgver}"

  # https://github.com/neovim/neovim/issues/6023
  patch -Np1 -i ../4a46ab8de9a9a9aee36546740c45b9e65a9e7dc9.patch
}

build() {
  mkdir -p "${srcdir}/build"
  cd "${srcdir}/build"

  cmake "../neovim-${pkgver}" \
        -G Ninja \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DENABLE_JEMALLOC=ON
  cmake --build .
}

check() {
  cd "${srcdir}/build"
  ./bin/nvim --version
  ./bin/nvim --headless -u NONE -i NONE -c ':quit'
}

package() {
  cd "${srcdir}/build"
  DESTDIR="${pkgdir}" cmake --build . --target install

  cd "${srcdir}/neovim-${pkgver}"
  install -Dm644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
  install -Dm644 runtime/nvim.desktop "${pkgdir}/usr/share/applications/nvim.desktop"
  install -Dm644 runtime/nvim.png "${pkgdir}/usr/share/pixmaps/nvim.png"

  # Make Arch vim packages work
  mkdir -p "${pkgdir}"/usr/share/vim
  echo "set runtimepath+=/usr/share/vim/vimfiles" > "${pkgdir}"/usr/share/nvim/sysinit.vim
}

# vim:set sw=2 sts=2 et:
