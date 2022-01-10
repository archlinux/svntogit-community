# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Felix Yan <felixonmars@archlinux.org>
# Contributor: Mario Finelli <mario at finel dot li>
# Contributor: Artem Vorotnikov <artem at vorotnikov dot me>

_gemname=ffi
pkgname=ruby-$_gemname
pkgver=1.15.5
pkgrel=1
pkgdesc='Ruby FFI'
arch=('x86_64')
url='https://github.com/ffi/ffi'
license=('BSD')
depends=('ruby')
makedepends=('ruby-rdoc')
options=('!emptydirs')
source=("https://rubygems.org/downloads/$_gemname-$pkgver.gem")
noextract=("$_gemname-$pkgver.gem")
sha512sums=('074df34edffc7038ab08199350a97b32280d61ea15dd85d459b008bd3363ec5403b4e533621c8e460e5288f01fec944bff9b149851b819e85bab75ad2362227c')
b2sums=('002e2df130f5bde1e93c7c5fb85fa30641b8ded2396f7e7761e1df3944d860f339294b4ce229b9e14e682fbadfa381338977cab7067bb41611b3fff28243bcb9')

package() {
  local _gemdir="$(ruby -e'puts Gem.default_dir')"

  gem install \
    --verbose \
    --ignore-dependencies \
    --no-document \
    --no-user-install \
    --install-dir "$pkgdir/$_gemdir" \
    --bindir "$pkgdir/usr/bin" \
    "$_gemname-$pkgver.gem"

  # delete unnecessary files & folders
  cd "$pkgdir/$_gemdir"
  find . -type f -name 'gem_make.out' -delete -o -name 'mkmf.log' -delete
  rm -vrf cache
  cd "gems/$_gemname-$pkgver"
  rm -vrf Gemfile Rakefile "$_gemname.gemspec" ext rakelib
  find lib/ffi/platform/* -prune -not -name "$CARCH-linux" -exec rm -rf {} +

  # move documentation
  install -vd "$pkgdir/usr/share/doc/$pkgname"
  mv -v samples CHANGELOG.md README.md "$pkgdir/usr/share/doc/$pkgname"

  # move licenses
  install -vd "$pkgdir/usr/share/licenses/$pkgname"
  mv -v LICENSE* COPYING "$pkgdir/usr/share/licenses/$pkgname"

  # generate Ruby documentation
  rdoc \
    --format ri \
    --output "$pkgdir$_gemdir/doc/$_gemname-$pkgver/ri" \
    ./lib
  # delete unnecessary artifacts
  rm -rf "$pkgdir$_gemdir/doc/$_gemname-$pkgver/ri/"{lib,created.rid}
}
