# Maintainer: Vesa Kaihlavirta <vegai@iki.fi>
# Contributor: Andres Perera <andres87p gmail>
# Contributor: Matthew Bauer <mjbauer95@gmail.com>
# Contributor: Christian Himpel <chressie at gmail dot com>
pkgname=go
pkgver=4623
pkgrel=1
pkgdesc='Google Go compiler and tools'
arch=(i686 x86_64)
url=http://golang.org/
license=(custom)
depends=(sh)
makedepends=(mercurial)
options=(!strip !makeflags)
install=$pkgname.install
source=($pkgname.install $pkgname.sh)

_hgroot=https://go.googlecode.com/hg/
_hgrepo=release

build() {
  rm -rf build
  cp -r $_hgrepo build

  mkdir build/bin
  cd build/src

  ARCH=$(uname -m)

  [ "$ARCH" == "i686" ]   && GOARCH=386
  [ "$ARCH" == "arm" ]    && GOARCH=arm
  [ "$ARCH" == "x86_64" ] && GOARCH=amd64

  GOOS=linux \
  GOROOT=$srcdir/build \
  GOBIN=$GOROOT/bin \
  make all || return 1

  cd $srcdir/build
  install -Dm644 LICENSE $pkgdir/usr/share/licenses/go/LICENSE
  install -Dm644 misc/bash/go $pkgdir/etc/bash_completion.d/go
  install -Dm644 misc/emacs/go-mode-load.el $pkgdir/usr/share/emacs/site-lisp/go-mode-load.el
  install -Dm644 misc/emacs/go-mode.el $pkgdir/usr/share/emacs/site-lisp/go-mode.el
  install -Dm644 misc/vim/go.vim $pkgdir/usr/share/vim/vimfiles/syntax/go.vim

  rm -rf misc/{bash,emacs,vim}
  mkdir -p $pkgdir/{etc/profile.d,usr/{share/go,lib/go}}

  cp -r bin $pkgdir/usr
  cp -r doc misc -t $pkgdir/usr/share/go
  cp -r pkg $pkgdir/usr/lib/go
  install  $srcdir/go.sh $pkgdir/etc/profile.d/ 
}

md5sums=('6055b666a95133e75abaa3e19d47eba8'
         '95b2ddb38efd5b616fd19b41ef9044ff')
