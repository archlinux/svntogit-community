# Maintainer: Stefan Husmann <stefan-husmann@t-online.de>
# Contributor: William Rea <sillywilly@gmail.com>
# Contributor: Andrea Scarpino <bash.lnx@gmail.com>

pkgname=ruby-zoom
_pkgname=zoom
pkgver=0.4.1
pkgrel=2
pkgdesc="A Ruby binding to the Z39.50 Object-Orientation Model"
arch=('i686' 'x86_64')
url="http://rubyforge.org/projects/ruby-zoom/"
license=('LGPL')
depends=('ruby' 'yaz')
source=(http://rubyforge.org/frs/download.php/28211/$_pkgname-$pkgver.gem)
md5sums=('8f061f41f607dede2f26d7055b5cd3ac')

build() {
  cd $srcdir
  local _gemdir="$(ruby -rubygems -e'puts Gem.default_dir')"
  gem install --ignore-dependencies -i \
    $pkgdir/${_gemdir} ${_pkgname}-$pkgver.gem
}
